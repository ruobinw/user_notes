<?php
/**
 * @file
 * user_notes.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function user_notes_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'store user notes'.
  $permissions['store user notes'] = array(
    'name' => 'store user notes',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user_notes',
  );

  return $permissions;
}
