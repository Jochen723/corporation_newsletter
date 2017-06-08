<?php
/**
 * Created by PhpStorm.
 * User: jonaskortum
 * Date: 06.06.17
 * Time: 14:22
 */

function newsletter_builder_configure_newsetter_form() {

    $nodes = array();

    $sql = "SELECT * FROM {node} as node WHERE node.type = 'test'";
    $result = db_query($sql);

    foreach ($result as $item) {
        $nodes[$item->nid] = $item->title;
    }

    $form['news_checkboxes'] = array(
        '#type' => 'checkboxes',
        '#options' => $nodes,
    );

    $form['news'] = array(
        '#type' => 'submit',
        '#value' => 'speichern',
        '#submit' => array('newsletter_builder_save_newsletter')
    );

    return $form;
}

function newsletter_builder_save_newsletter($form, &$form_state) {

}