<?php
/**
 * @file
 * The admin pages for the User Contact Forms module.
 */

function contact_user_admin_settings() {
  $form['contact_user_form_information'] = array(
    '#type' => 'textarea',
    '#title' => t('Additional information'),
    '#default_value' => variable_get('contact_user_form_information', t('You can send a message to %username using the contact form below.')),
    '#description' => t('Information to show on the user contact page. Us can use the variable <em>%username</em> and the username of the person being contacted will be substituted.'),
  );
  $form['contact_user_hourly_threshold'] = array(
    '#type' => 'select',
    '#title' => t('Hourly threshold'),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50)),
    '#default_value' => variable_get('contact_user_hourly_threshold', 3),
    '#description' => t('The maximum number of contact user form submissions a user can perform per hour.'),
  );
  $form['contact_user_subject_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject Prefix'),
    '#default_value' => variable_get('contact_user_subject_prefix', t('User contact')),
    '#description' => t('Customize the prefix that shows up between [] in the email subject line.'),
    '#size' => 40,
    '#maxlength' => 255,
  );
  $form['contact_user_confirmation_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Confirmation message'),
    '#default_value' => variable_get('contact_user_confirmation_message', t('Your message has been sent.')),
    '#description' => t('Enter the confirmation message displayed when the form is submitted.'),
  );
  return system_settings_form($form);
}