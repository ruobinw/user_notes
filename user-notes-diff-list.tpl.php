<div class="<?php print $classes; ?>">
  <div class="submitted">
    <?php print t('This is a note attached to node No.@nid. The serial no. of the note is @ntid', array(
      '@nid' => $nid,
      '@ntid' => $ntid,
    )); ?>
  </div>
  <div class="content"<?php print $notes; ?>>
    <?php
      print render($notes);
    ?>
  </div>
</div>