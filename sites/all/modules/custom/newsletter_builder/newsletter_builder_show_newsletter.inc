<?php
/**
 * Created by PhpStorm.
 * User: jonaskortum
 * Date: 06.06.17
 * Time: 07:36
 */

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
    $html_table = "this is a table";

    return $html_table;
}