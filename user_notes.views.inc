<?php

function user_notes_views_data() {
  // This example describes how to write hook_views_data() for the following
  // table:
  //
  // CREATE TABLE user_notes (
  //   ntid INT(11) NOT NULL         COMMENT 'Primary key; refers to {node}.nid.',
  //   plain_text_field VARCHAR(32) COMMENT 'Just a plain text field.',
  //   numeric_field INT(11)        COMMENT 'Just a numeric field.',
  //   boolean_field INT(1)         COMMENT 'Just an on/off field.',
  //   timestamp_field INT(8)       COMMENT 'Just a timestamp field.',
  //   PRIMARY KEY(nid)
  // );

  // First, the entry $data['user_notes']['table'] describes properties of
  // the actual table – not its content.

  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data['user_notes']['table']['group'] = t('User notes');

  // Define this as a base table – a table that can be described in itself by
  // views (and not just being brought in as a relationship). In reality this
  // is not very useful for this table, as it isn't really a distinct object of
  // its own, but it makes a good example.
  $data['user_notes']['table']['base'] = array(
    'field' => 'ntid', // This is the identifier field for the view.
    'title' => t('User notes'),
    'help' => t('Table contains notes information.'),
    'weight' => -10,
  );

  // This table references the {node} table. The declaration below creates an
  // 'implicit' relationship to the node table, so that when 'node' is the base
  // table, the fields are automatically available.
  $data['user_notes']['table']['join'] = array(
    
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'node' => array(
      'left_field' => 'ntid',
      //'field' => 'nid',
    ),
  );

  // Next, describe each of the individual fields in this table to Views. This
  // is done by describing $data['user_notes']['FIELD_NAME']. This part of
  // the array may then have further entries:
  //   - title: The label for the table field, as presented in Views.
  //   - help: The description text for the table field.
  //   - relationship: A description of any relationship handler for the table
  //     field.
  //   - field: A description of any field handler for the table field.
  //   - sort: A description of any sort handler for the table field.
  //   - filter: A description of any filter handler for the table field.
  //   - argument: A description of any argument handler for the table field.
  //   - area: A description of any handler for adding content to header,
  //     footer or as no result behaviour.
  //
  // The handler descriptions are described with examples below.

  // Note ID table field.
  $data['user_notes']['ntid'] = array(
    'title' => t('Note ID'),
    'help' => t('Primary keys that references a note.'),
    
    // Define a relationship to the {node} table, so user_notes views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'user_notes', // The name of the table to join with.
      'base field' => 'ntid', // The name of the field on the joined table.
      // 'field' => 'ntid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Default label for the relationship'),
      'title' => t('user notes'),
      'help' => t('More information on this relationship'),
    ),
  );

  // Note text field.
  $data['user_notes']['notes'] = array(
    'title' => t('Note'),
    'help' => t('Note text field.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Node ID text field.
  $data['user_notes']['nid'] = array(
    'title' => t('Node ID'),
    'help' => t('Node ID that references to a node'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  //User ID text field.
  $data['user_notes']['nid'] = array(
    'title' => t('Node ID'),
    'help' => t('Node ID that references to a node'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );



  // // Example boolean field.
  // $data['user_notes']['boolean_field'] = array(
  //   'title' => t('Boolean field'),
  //   'help' => t('Just an on/off field.'),
  //   'field' => array(
  //     'handler' => 'views_handler_field_boolean',
  //     'click sortable' => TRUE,
  //   ),
  //   'filter' => array(
  //     'handler' => 'views_handler_filter_boolean_operator',
      
  //     // Note that you can override the field-wide label:
  //     'label' => t('Published'),
      
  //     // This setting is used by the boolean filter handler, as possible option.
  //     'type' => 'yes-no',
      
  //     // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment.
  //     'use equal' => TRUE,
  //   ),
  //   'sort' => array(
  //     'handler' => 'views_handler_sort',
  //   ),
  // );

  // // Example timestamp field.
  // $data['user_notes']['timestamp_field'] = array(
  //   'title' => t('Timestamp field'),
  //   'help' => t('Just a timestamp field.'),
  //   'field' => array(
  //     'handler' => 'views_handler_field_date',
  //     'click sortable' => TRUE,
  //   ),
  //   'sort' => array(
  //     'handler' => 'views_handler_sort_date',
  //   ),
  //   'filter' => array(
  //     'handler' => 'views_handler_filter_date',
  //   ),
  // );

  return $data;
}