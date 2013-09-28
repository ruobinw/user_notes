<?php

function user_notes_views_data() {
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
      'left_field' => 'nid',
      'field' => 'nid',
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
    // Define a relationship to the {node} table, so user_notes views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'node', // The name of the table to join with.
      'base field' => 'nid', // The name of the field on the joined table.
      // 'field' => 'ntid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Default label for the relationship'),
      'title' => t('Node'),
      'help' => t('Node table.'),
    ),
  );
  
  //User ID text field.
  $data['user_notes']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('User ID that references to a user'),
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

  // User notes timestamp field.
  $data['user_notes']['created'] = array(
    'title' => t('Created'),
    'help' => t('Date and time the note was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  // User notes timestamp field.
  $data['user_notes']['changed'] = array(
    'title' => t('Changed'),
    'help' => t('Date and time the note was last changed.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // // User notes edit link.
  // $data['user_notes']['edit_note'] = array(
  //   'field' => array(
  //     'title' => t('Edit'),
  //     'help' => t('Provide a simple link to edit the content.'),
  //     'handler' => 'views_handler_field_user_notes_edit',
  //   ),
  // );

  // $data['node']['delete_node']['moved to'] = array('views_entity_node', 'delete_node');
  // $data['views_entity_node']['delete_node'] = array(
  //   'field' => array(
  //     'title' => t('Delete link'),
  //     'help' => t('Provide a simple link to delete the content.'),
  //     'handler' => 'views_handler_field_node_link_delete',
  //   ),
  // );

  return $data;
}