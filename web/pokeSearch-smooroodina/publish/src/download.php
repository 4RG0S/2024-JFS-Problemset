<?php
require 'vendor/autoload.php';
use PhpOffice\PhpSpreadsheet\Spreadsheet;
use PhpOffice\PhpSpreadsheet\Writer\Xlsx;


if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_FILES['file'])) {
        $xmlContent = file_get_contents($_FILES['file']['tmp_name']);
        $xmlContent = str_replace("SYSTEM", "", $xmlContent);
        $xmlContent = str_replace("flag", "", $xmlContent);

        $xml = simplexml_load_string($xmlContent, null, LIBXML_NOENT);
        if (!$xml) {
            echo "XML Parsing failed.";
            exit;
        }
        $data_labels = ["no", "dex", "name", "name-japanese", "name-japanese-roman", "sprite", "sprite-shiny", "form", "sex", "slug"];
        $data = [];
        foreach ($xml->member as $member) {
            $data[] = [
                (string)$member->no,
                (string)$member->dex,
                (string)$member->name,
                (string)$member->{'name-japanese'},
                (string)$member->{'name-japanese-roman'},
                (string)$member->sprite,
                (string)$member->{'sprite-shiny'},
                (string)$member->form,
                (string)$member->sex,
                (string)$member->slug,
            ];
        }
        $spreadsheet = new Spreadsheet();
        $sheet = $spreadsheet->getActiveSheet();
        $sheet->fromArray($data_labels, NULL, 'A1');
        $sheet->fromArray($data, NULL, 'A2');

        $filename = 'members.xlsx';
        header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
        header("Content-Disposition: attachment; filename=\"$filename\"");
        $writer = new Xlsx($spreadsheet);
        $writer->save("php://output");
    }
}

?>