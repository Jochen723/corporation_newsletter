<?php
/**
 * Created by PhpStorm.
 * User: jonaskortum
 * Date: 06.06.17
 * Time: 07:36
 */

function newsletter_builder_show_newsletter_form() {

    $newsletter_id = arg(1);

    $nid = 0;

    $sql = "SELECT * FROM {newsletter} WHERE newsletter_id = ".$newsletter_id;
    $newsletter_result = db_query($sql);

    foreach ($newsletter_result as $newsletter) {
        $nid = $newsletter->nid;
    }

    $node = node_load($nid);



    $content = newsletter_builder_get_html_content($node, 'test_id');

    $form['test']['form_item'] = array(
        '#type' => 'markup',
        '#title' => t('My Form Item'),
        '#prefix' => $content,
    );

    return $form;
}


function newsletter_builder_newsletter_overview_form() {

    $content = newsletter_builder_get_newsletter_overview();

    $form['test']['form_item'] = array(
        '#type' => 'markup',
        '#title' => t('My Form Item'),
        '#prefix' => $content,
    );

    return $form;
}

function newsletter_builder_get_newsletter_overview() {

    global $base_url;

    $sql = "SELECT * FROM {newsletter} ORDER BY newsletter_id";

    //Der Kopf der Tabelle wird erstellt
    $html_table = "<table><th>Nummer</th><th>Sende-Datum</th> <th>zugehöriger Node</th>";

    $newsletter_result = db_query($sql);

    //Es wird über alle Termine iteriert
    foreach ($newsletter_result as $newsletter) {

        //Für jeden Termin wird eine neue Zeile innerhalb der Tabelle erstellt
        $html_table = $html_table . "
            <tr>
                <td>$newsletter->newsletter_id</td>
                <td>$newsletter->date</td>
                <td>
                <ul>
                    <li><a href='" . $base_url . "/node/" . $newsletter->nid . "'>Node anzeigen</a></li>
                    <li><a href='" . $base_url . "/show_newsletter/" . $newsletter->newsletter_id . "'>Newsletter anzeigen</a></li>
                </ul>
            </tr>";
    }

    //Die Tabelle wird geschlossen
    $html_table .= "</table>";

    return $html_table;
}