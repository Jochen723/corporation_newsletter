<?php
/**
 * Created by PhpStorm.
 * User: jonaskortum
 * Date: 06.06.17
 * Time: 07:33
 */

function newsletter_builder_save_newsletter($node, $date) {

    $sql = "INSERT INTO {newsletter} (date, nid) VALUES ('".$date."',".$node->nid.") ";
    db_query($sql);
}