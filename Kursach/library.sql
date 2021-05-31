-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1:3306
-- Время создания: Май 31 2021 г., 18:41
-- Версия сервера: 8.0.19
-- Версия PHP: 7.1.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `base2.0`
--

-- --------------------------------------------------------

--
-- Структура таблицы `base_table_admin`
--

CREATE TABLE `base_table_admin` (
  `id` int NOT NULL,
  `name` text NOT NULL,
  `password` text NOT NULL,
  `role` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `base_table_admin`
--

INSERT INTO `base_table_admin` (`id`, `name`, `password`, `role`) VALUES
(1, 'teacher_math', '1234', 'math'),
(5, 'teacher_prog', '1234', 'prog'),
(6, 'teacher_phy', '1234', 'phy'),
(7, 'teacher_engl', '1234', 'engl');

-- --------------------------------------------------------

--
-- Структура таблицы `base_table_user`
--

CREATE TABLE `base_table_user` (
  `id` int NOT NULL,
  `name` text NOT NULL,
  `password` text NOT NULL,
  `link_homework_math` text CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `link_answer_math` text CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `link_homework_prog` text NOT NULL,
  `link_answer_prog` text NOT NULL,
  `link_homework_phy` text NOT NULL,
  `link_answer_phy` text NOT NULL,
  `link_homework_engl` text NOT NULL,
  `link_answer_engl` text NOT NULL,
  `score` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `base_table_user`
--

INSERT INTO `base_table_user` (`id`, `name`, `password`, `link_homework_math`, `link_answer_math`, `link_homework_prog`, `link_answer_prog`, `link_homework_phy`, `link_answer_phy`, `link_homework_engl`, `link_answer_engl`, `score`) VALUES
(1, 'user', '1234', '', '', '', '', '', '', '', '', 45),
(2, 'user2', '1234', '', '', '', '', '', '', '', '', 0),
(4, 'user3', '1234', '', '', '', '', '', '', '', '', 0);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `base_table_admin`
--
ALTER TABLE `base_table_admin`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `base_table_user`
--
ALTER TABLE `base_table_user`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `base_table_admin`
--
ALTER TABLE `base_table_admin`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT для таблицы `base_table_user`
--
ALTER TABLE `base_table_user`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
