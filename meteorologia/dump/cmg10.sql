-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: 10-Jun-2021 às 20:00
-- Versão do servidor: 8.0.14
-- versão do PHP: 7.3.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cmg10`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `categorias`
--

CREATE TABLE `categorias` (
  `cod_categoria` int(3) NOT NULL,
  `descricao` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `categorias`
--

INSERT INTO `categorias` (`cod_categoria`, `descricao`) VALUES
(1, 'Informatica'),
(2, 'Eletrica'),
(3, 'EPI'),
(4, 'Outros'),
(5, 'pegacarai'),
(6, 'pegacarai'),
(7, 'pegacarai'),
(8, '3'),
(9, 'pegacarai');

-- --------------------------------------------------------

--
-- Estrutura da tabela `centros_custo`
--

CREATE TABLE `centros_custo` (
  `cod_centro` int(6) NOT NULL,
  `descricao` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `centros_custo`
--

INSERT INTO `centros_custo` (`cod_centro`, `descricao`) VALUES
(1, 'TI'),
(2, 'USINAGEM'),
(3, 'ALMOXARIFADO'),
(4, 'tedte'),
(5, 'tedte'),
(6, 'pega carai'),
(7, 'pega carai 2'),
(8, 'tedte'),
(9, 'pega carai 2'),
(10, '5');

-- --------------------------------------------------------

--
-- Estrutura da tabela `entradas`
--

CREATE TABLE `entradas` (
  `cod_entrada` int(6) NOT NULL,
  `cod_forn` int(3) DEFAULT NULL,
  `cod_mat` int(6) DEFAULT NULL,
  `nf_num` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `data_nf` varchar(10) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `data_entrada` varchar(10) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `quantidade` int(6) DEFAULT NULL,
  `recebedor` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `obs` varchar(150) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `entradas`
--

INSERT INTO `entradas` (`cod_entrada`, `cod_forn`, `cod_mat`, `nf_num`, `data_nf`, `data_entrada`, `quantidade`, `recebedor`, `obs`) VALUES
(1, 1, 2, '121125512', '10/10/2020', '11/10/2020', 2, 'tiago beloti', 'Saida sem requisição'),
(2, 1, 3, '15125122511', '10/12/2020', '11/12/2020', 10, 'tiago', 'saida normal para fulano'),
(3, 2, 2, '451212', '10/09/2021', '10/09/2021', 5, 'teste', 'teste3'),
(4, 3, 3, '55455455', '09/09/2020', '10/09/2021', 5, 'teste rapido', 'rapido a entrega');

-- --------------------------------------------------------

--
-- Estrutura da tabela `entradas_materiais`
--

CREATE TABLE `entradas_materiais` (
  `cod_entrada` int(6) NOT NULL,
  `cod_material` int(6) DEFAULT NULL,
  `quantidade` int(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `entradas_materiais`
--

INSERT INTO `entradas_materiais` (`cod_entrada`, `cod_material`, `quantidade`) VALUES
(1, 2, 5),
(2, 3, 6),
(3, 3, 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `familias`
--

CREATE TABLE `familias` (
  `cod_familia` int(3) NOT NULL,
  `descricao` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `familias`
--

INSERT INTO `familias` (`cod_familia`, `descricao`) VALUES
(1, 'Mouse'),
(2, 'Luva'),
(3, 'Adaptador de tomada'),
(4, 'Fita isolante'),
(5, 'Cabo RJ45'),
(6, NULL),
(7, NULL),
(8, NULL),
(9, 'teste'),
(10, 'pegaaaaaaaa'),
(11, 'teste'),
(12, 'teste'),
(13, 'teste'),
(14, 'pegaaaaaaaa'),
(15, '4'),
(16, '');

-- --------------------------------------------------------

--
-- Estrutura da tabela `fornecedores`
--

CREATE TABLE `fornecedores` (
  `cod_fornecedor` int(3) NOT NULL,
  `razao_social` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `fantasia` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `cnpj` varchar(25) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `ie` varchar(16) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `endereco` varchar(150) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `telefone` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `contato` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `fornecedores`
--

INSERT INTO `fornecedores` (`cod_fornecedor`, `razao_social`, `fantasia`, `cnpj`, `ie`, `endereco`, `telefone`, `contato`) VALUES
(1, 'acb comercio ltda', 'acb comercnio', '13249846/0002-02', '330.663.656.96', 'av joao palo, 782 andar 3 sala 31', '14985852252', 'a@a.com.br (joao)'),
(2, 'teste razao s/a', 'teste razao', '15652512/0004-52', '556-669-965-66', 'rua reboucas, 40', '14899568569', 'teste@teste.com.br (kleber)');

-- --------------------------------------------------------

--
-- Estrutura da tabela `funcionarios`
--

CREATE TABLE `funcionarios` (
  `cod_func` int(3) NOT NULL,
  `cod_centro_custo` int(3) DEFAULT NULL,
  `nome` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `email` varchar(60) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `ramal` varchar(4) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `celular` varchar(10) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `funcionarios`
--

INSERT INTO `funcionarios` (`cod_func`, `cod_centro_custo`, `nome`, `email`, `ramal`, `celular`) VALUES
(1, 1, 'tiago', 't@t.com.br', '6664', '998765432'),
(2, 1, 'emerson', 'e@e.com.br', '6654', '999876543'),
(3, 2, 'fulano', 'f@f.com.br', '7766', '987654321'),
(4, 3, 'ciclano da silva', 'cs@cs.com.br', '7464', '988765678'),
(5, 2, 'bibos aguiar', 'ba@ba.com.br', '7444', '877837465');

-- --------------------------------------------------------

--
-- Estrutura da tabela `materiais`
--

CREATE TABLE `materiais` (
  `cod_material` int(6) NOT NULL,
  `cod_area` int(3) NOT NULL,
  `cod_categoria` int(3) NOT NULL,
  `cod_familia` int(3) NOT NULL,
  `cod_mat_sap` varchar(15) COLLATE utf8mb4_unicode_ci NOT NULL,
  `descricao` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `unit_medida` varchar(3) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_validade` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `quantidade` int(6) NOT NULL,
  `obs` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `materiais`
--

INSERT INTO `materiais` (`cod_material`, `cod_area`, `cod_categoria`, `cod_familia`, `cod_mat_sap`, `descricao`, `unit_medida`, `data_validade`, `quantidade`, `obs`) VALUES
(1, 1, 1, 1, 'P0005', 'Mouse Optico Preto', 'PC', 'N', 10, 'TESTE'),
(2, 1, 2, 2, 'M00065-T', 'Luva protetora', 'PAR', '20/12/2022', 5, 'TESTE LUVA 02'),
(3, 2, 2, 4, 'M778787', 'Fita Isolante liquida', 'PC', '10/10/2050', 100, 'TESTE DE TUBO ADESIVO');

-- --------------------------------------------------------

--
-- Estrutura da tabela `setor`
--

CREATE TABLE `setor` (
  `cod_area` int(3) NOT NULL,
  `descricao` varchar(45) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Extraindo dados da tabela `setor`
--

INSERT INTO `setor` (`cod_area`, `descricao`) VALUES
(1, ''),
(2, ''),
(16, ''),
(17, ''),
(18, ''),
(19, ''),
(20, ''),
(21, ''),
(22, ''),
(23, ''),
(24, ''),
(25, ''),
(26, ''),
(27, ''),
(28, 'teste'),
(29, 'teste'),
(30, 'teste1'),
(31, 'teste2'),
(32, 'teste'),
(33, 'teste'),
(34, 'teste'),
(35, 'vaicarai'),
(36, 'agaoravai'),
(37, 'teste'),
(38, 'teste'),
(39, 'teste'),
(40, 'teste'),
(41, 'teste'),
(42, 'teste'),
(43, '');

-- --------------------------------------------------------

--
-- Stand-in structure for view `vw_entradas_mestre`
-- (See below for the actual view)
--
CREATE TABLE `vw_entradas_mestre` (
`COD_ENTRADA` int(6)
,`COD_FORN` int(3)
,`COD_MAT` int(6)
,`DATA_ENTRADA` varchar(10)
,`DATA_NF` varchar(10)
,`FORN_CNPJ` varchar(25)
,`FORN_CONTATO` varchar(100)
,`FORN_FANT` varchar(100)
,`FORN_TEL` varchar(60)
,`NF_NUM` varchar(100)
,`OBS` varchar(150)
,`QUANTIDADE` int(6)
,`RECEBEDOR` varchar(50)
);

-- --------------------------------------------------------

--
-- Stand-in structure for view `vw_funcionarios_centro_custos`
-- (See below for the actual view)
--
CREATE TABLE `vw_funcionarios_centro_custos` (
`CELULAR` varchar(10)
,`COD_CENTRO_CUSTO` int(3)
,`COD_FUNC` int(3)
,`DESCRICAO` varchar(100)
,`EMAIL` varchar(60)
,`NOME` varchar(100)
,`RAMAL` varchar(4)
);

-- --------------------------------------------------------

--
-- Stand-in structure for view `vw_materiais_mestres`
-- (See below for the actual view)
--
CREATE TABLE `vw_materiais_mestres` (
);

-- --------------------------------------------------------

--
-- Structure for view `vw_entradas_mestre`
--
DROP TABLE IF EXISTS `vw_entradas_mestre`;

CREATE ALGORITHM=UNDEFINED DEFINER=`cmg10`@`%` SQL SECURITY DEFINER VIEW `vw_entradas_mestre`  AS  select `entradas`.`cod_entrada` AS `COD_ENTRADA`,`entradas_materiais`.`cod_material` AS `COD_MAT`,`entradas_materiais`.`quantidade` AS `QUANTIDADE`,`entradas`.`cod_forn` AS `COD_FORN`,`fornecedores`.`fantasia` AS `FORN_FANT`,`fornecedores`.`cnpj` AS `FORN_CNPJ`,`fornecedores`.`telefone` AS `FORN_TEL`,`fornecedores`.`contato` AS `FORN_CONTATO`,`entradas`.`nf_num` AS `NF_NUM`,`entradas`.`data_nf` AS `DATA_NF`,`entradas`.`data_entrada` AS `DATA_ENTRADA`,`entradas`.`recebedor` AS `RECEBEDOR`,`entradas`.`obs` AS `OBS` from ((`entradas` join `fornecedores` on((`fornecedores`.`cod_fornecedor` = `entradas`.`cod_forn`))) join `entradas_materiais` on(((`entradas_materiais`.`cod_material` = `entradas`.`cod_mat`) and (`entradas_materiais`.`cod_entrada` = `entradas`.`cod_entrada`)))) order by `fornecedores`.`fantasia` ;

-- --------------------------------------------------------

--
-- Structure for view `vw_funcionarios_centro_custos`
--
DROP TABLE IF EXISTS `vw_funcionarios_centro_custos`;

CREATE ALGORITHM=UNDEFINED DEFINER=`cmg10`@`%` SQL SECURITY DEFINER VIEW `vw_funcionarios_centro_custos`  AS  select `funcionarios`.`cod_func` AS `COD_FUNC`,`funcionarios`.`nome` AS `NOME`,`funcionarios`.`cod_centro_custo` AS `COD_CENTRO_CUSTO`,`centros_custo`.`descricao` AS `DESCRICAO`,`funcionarios`.`email` AS `EMAIL`,`funcionarios`.`ramal` AS `RAMAL`,`funcionarios`.`celular` AS `CELULAR` from (`funcionarios` join `centros_custo` on((`centros_custo`.`cod_centro` = `funcionarios`.`cod_centro_custo`))) order by `funcionarios`.`cod_centro_custo` ;

-- --------------------------------------------------------

--
-- Structure for view `vw_materiais_mestres`
--
DROP TABLE IF EXISTS `vw_materiais_mestres`;

CREATE ALGORITHM=UNDEFINED DEFINER=`cmg10`@`%` SQL SECURITY DEFINER VIEW `vw_materiais_mestres`  AS  select `materiais`.`cod_material` AS `COD_MATERIAL`,`materiais`.`cod_area` AS `COD_AREA`,`areas`.`descricao` AS `DESC_AREA`,`materiais`.`cod_categoria` AS `COD_CATEGORIA`,`categorias`.`descricao` AS `DESC_CATEGORIA`,`materiais`.`cod_familia` AS `COD_FAMILIA`,`familias`.`descricao` AS `DESC_FAMILIA`,`materiais`.`cod_mat_sap` AS `COD_MAT_SAP`,`materiais`.`descricao` AS `DESCRICAO`,`materiais`.`unit_medida` AS `UNIT_MEDIDA`,`materiais`.`data_validade` AS `DATA_VALIDADE`,`materiais`.`quantidade` AS `QUANTIDADE`,`materiais`.`obs` AS `OBS` from (((`materiais` join `areas` on((`areas`.`cod_area` = `materiais`.`cod_area`))) join `categorias` on((`categorias`.`cod_categoria` = `materiais`.`cod_categoria`))) join `familias` on((`familias`.`cod_familia` = `materiais`.`cod_familia`))) order by `materiais`.`cod_material` ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `categorias`
--
ALTER TABLE `categorias`
  ADD PRIMARY KEY (`cod_categoria`);

--
-- Indexes for table `centros_custo`
--
ALTER TABLE `centros_custo`
  ADD PRIMARY KEY (`cod_centro`);

--
-- Indexes for table `entradas`
--
ALTER TABLE `entradas`
  ADD PRIMARY KEY (`cod_entrada`);

--
-- Indexes for table `entradas_materiais`
--
ALTER TABLE `entradas_materiais`
  ADD PRIMARY KEY (`cod_entrada`);

--
-- Indexes for table `familias`
--
ALTER TABLE `familias`
  ADD PRIMARY KEY (`cod_familia`);

--
-- Indexes for table `fornecedores`
--
ALTER TABLE `fornecedores`
  ADD PRIMARY KEY (`cod_fornecedor`);

--
-- Indexes for table `funcionarios`
--
ALTER TABLE `funcionarios`
  ADD PRIMARY KEY (`cod_func`);

--
-- Indexes for table `materiais`
--
ALTER TABLE `materiais`
  ADD PRIMARY KEY (`cod_material`);

--
-- Indexes for table `setor`
--
ALTER TABLE `setor`
  ADD PRIMARY KEY (`cod_area`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `categorias`
--
ALTER TABLE `categorias`
  MODIFY `cod_categoria` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `centros_custo`
--
ALTER TABLE `centros_custo`
  MODIFY `cod_centro` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `entradas`
--
ALTER TABLE `entradas`
  MODIFY `cod_entrada` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `familias`
--
ALTER TABLE `familias`
  MODIFY `cod_familia` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `fornecedores`
--
ALTER TABLE `fornecedores`
  MODIFY `cod_fornecedor` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `funcionarios`
--
ALTER TABLE `funcionarios`
  MODIFY `cod_func` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `materiais`
--
ALTER TABLE `materiais`
  MODIFY `cod_material` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `setor`
--
ALTER TABLE `setor`
  MODIFY `cod_area` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=44;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
