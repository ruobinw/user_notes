<?php

/**
 * @file
 * Definition of views_handler_field_user_notes_link_edit.
 */

/**
 * Field handler to present a link user note edit.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_notes_link_edit extends views_handler_field_user_notes_link {

  /**
   * Renders the link.
   */
  function render_link($note, $values) {
    // // Ensure user has access to edit this node.
    // if (!node_access('update', $node)) {
    //   return;
    // }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "note/$ntid/edit_note";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return $text;
  }
}