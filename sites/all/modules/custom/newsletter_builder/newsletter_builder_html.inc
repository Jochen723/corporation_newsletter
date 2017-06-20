<?php
/**
 * Created by PhpStorm.
 * User: jonaskortum
 * Date: 02.06.17
 * Time: 11:19
 */

function newsletter_builder_get_html_content($node, $pw) {

    $html = '<p><font face="verdana" size="10" color="green">This is some text! '.$node->nid.'</font></p>';

    global $base_url;

    $interest = $base_url . '/newsletter_interest/' . $node->nid . '/' . $pw;
    $participation = $base_url . '/newsletter_participation/' . $node->nid . '/' . $pw;
    $no_interest = $base_url . '/newsletter_no_interest/' . $node->nid . '/' .  $pw;
    $no_participation = $base_url . '/newsletter_no_participation/' . $node->nid . '/' . $pw;

    //Button für die Interesse an einem Event
    $interest = '
    <td align="center" width="40%" style="background-color: #52b166; box-shadow: 0px 1px 4px rgba(0,0,0,.2);">
        <a href=' . $interest . ' style="text-decoration:none;">
            <table width="100%" cellpadding="10">
                <tr>
                    <td
                        style="
                        font-family: Fira, Arial, sans-serif;
                        text-align: center;
                        color: #ff0000;
                        text-decoration: none;
                        font-size: 12px;
                        letter-spacing:.5px;
                        text-transform: uppercase;">
                        Ich bin interessiert
                    </td>
                </tr>
            </table>
        </a>
    </td>
    <td width="20">
    </td>'; //Platzhalter zwischen den Buttons


    //Button für die Desinteresse an einem Event
    $noInterest = '
    <td align="center" width="40%" style="background-color: #444; box-shadow: 0px 1px 4px rgba(0,0,0,.2);">
        <a href=' . $no_interest . ' style="text-decoration:none;">
            <table width="100%" cellpadding="10">
                <tr>
                    <td
                        style="
                        font-family: Fira, Arial, sans-serif;
                        text-align: center;
                        color: #ff0000;
                        text-decoration: none;
                        font-size: 12px;
                        letter-spacing:.5px;
                        text-transform: uppercase;">
                        Ich bin nicht interessiert
                    </td>
                </tr>
            </table>
        </a>
    </td>
    <td width="20">
    </td>'; //Platzhalter zwischen den Buttons

    //Button für die Zusage zu einem Event
    $participation = '
    <td align="center" width="40%" style="background-color: #52b166; box-shadow: 0px 1px 4px rgba(0,0,0,.2);">
        <a href=' . $participation . ' style="text-decoration:none;">
            <table width="100%" cellpadding="10">
                <tr>
                    <td
                        style="
                        font-family: Fira, Arial, sans-serif;
                        text-align: center;
                        color: #ff0000;
                        text-decoration: none;
                        font-size: 12px;
                        letter-spacing:.5px;
                        text-transform: uppercase;">
                        Ich nehme teil
                    </td>
                </tr>
            </table>
        </a>
    <td>';

    //Button für die Absage an einem Event
    $noParticipation = '
    <td align="center" width="40%" style="background-color: #444; box-shadow: 0px 1px 4px rgba(0,0,0,.2);">
        <a href=' . $no_participation . ' style="text-decoration:none;">
            <table width="100%" cellpadding="10">
                <tr>
                    <td
                        style="
                        font-family: Fira, Arial, sans-serif;
                        text-align: center;
                        color: #ff0000;
                        text-decoration: none;
                        font-size: 12px;
                        letter-spacing:.5px;
                        text-transform: uppercase;">
                        Ich nehme nicht mehr teil
                    </td>
                </tr>
            </table>
        </a>
    </td>';


/*
    $html .= $interest;
    $html .= $noInterest;
    $html .= $participation;
    $html .= $noParticipation;
*/

    $html = '
    <table border="1" width="100%">
        <tr>
            <th width="20%" font color="#fff" bgcolor="#C8C8C8" align="left">&nbsp;</th>
            <th font color="#fff" bgcolor="#C8C8C8" align="left">&nbsp;</th>
        </tr>
        <tr>
            <td>Titel</td>
            <td>'.$node->title.'</td>
        </tr>
        <tr>
            <td>Forschungsprogramm</td>
            <td>'.$node->field_forschungsprogramm["und"][0]["value"].'</td>
        </tr>
        <tr>
            <td>Förderung durch</td>
            <td>'.$node->field_f_rderung_durch["und"][0]["value"].'</td>
        </tr>
        <tr>
            <td>Veröffentlicht am</td>
            <td>'.$node->field_ver_ffentlicht_am["und"][0]["value"].'</td>
        </tr>
        <tr>
            <td>Stichtag</td>
            <td>'.$node->field_stichtag["und"][0]["value"].'</td>
        </tr>
    </table>
    <br>';

    $html .= '
    <table border="1" width="100%">
        <tr>
            <th width="20%" font color="#fff" bgcolor="#C8C8C8" align="left">&nbsp;</th>
            <th font color="#fff" bgcolor="#C8C8C8" align="left">&nbsp;</th>
        </tr>
        <tr>
            <td>Zweck</td>
            <td>'.$node->field_zweck["und"][0]["value"].'</td>
        </tr>
        <tr>
            <td>Keywords aus der Ausschreibung</td>
            <td>'.$node->field_keywords_aus_der_auschreib["und"][0]["value"].'</td>
        </tr>
        <tr>
            <td>Zuwendungsempfänger</td>
            <td>'.$node->field_zuwendungsempf_nger["und"][0]["value"].'</td>
        </tr>
    </table>
    <br>';

    $html .= '
    <table border="1" width="100%">
        <tr>
            <th width="20%" font color="#fff" bgcolor="#C8C8C8" align="left">&nbsp;</th>
            <th font color="#fff" bgcolor="#C8C8C8" align="left">&nbsp;</th>
        </tr>
        <tr>
            <td>Webseite</td>
            <td>'.$node->field_webseite["und"][0]["value"].'</td>
        </tr>
        <tr>
            <td>Vorlagen</td>
            <td>'.$node->field_vorlagen["und"][0]["value"].'</td>
        </tr>
        <tr>
            <td>Hinweise</td>
            <td>'.$node->field_hinweise["und"][0]["value"].'</td>
        </tr>
    </table>';


    $html .= '
<br>
<br>';

    $html .= $node->field_kontaktdaten["und"][0]["value"];


    return $html;
}