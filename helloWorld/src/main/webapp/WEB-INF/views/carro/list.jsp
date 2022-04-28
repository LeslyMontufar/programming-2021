<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <title>O que e Spring MVC</title>
    </head>
    <body>
        <h1>Listagem de carros</h1>
        <table>
            <thead>
                <tr>
                    <th>Modelo</th>
                    <th>Marca</th>
                    <th>Ano</th>
                </tr>
            </thead>
            <tbody>
                <c:forEach var="carro" items="${carros}">
                    <tr>
                        <td>${carro.modelo}</td>
                        <td>${carro.marca}</td>
                        <td>${carro.ano}</td>
                    </tr>
                </c:forEach>
            </tbody>
        </table>
    </body>
</html>