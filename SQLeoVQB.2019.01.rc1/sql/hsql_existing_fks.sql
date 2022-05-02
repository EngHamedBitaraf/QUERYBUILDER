SELECT
     ref.FK_NAME AS FK_NAME,
     'INNER' AS JOIN_TYPE,
     ref.FKTABLE_SCHEM AS OWNER,
     ref.FKTABLE_NAME AS TABLE_NAME,
     ref.FKCOLUMN_NAME AS COLUMN_NAME,
     ref.PKTABLE_SCHEM AS PKTABLE_OWNER,
     ref.PKTABLE_NAME AS PKTABLE_NAME,
     '' AS PKTABLE_ALIAS,
     ref.PKCOLUMN_NAME AS PKCOLUMN_NAME,
     ref.PK_NAME AS PK_NAME
FROM
     INFORMATION_SCHEMA.SYSTEM_CROSSREFERENCE ref