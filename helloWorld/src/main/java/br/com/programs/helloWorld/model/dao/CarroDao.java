package br.com.programs.helloWorld.model.dao;

import br.com.programs.helloWorld.model.domain.Carro;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;

@Repository //notacao que informa que é um Bean:Camada de acesso a dados
public class CarroDao {

    private static List<Carro> carros;

    public CarroDao() {
        criarCarros();
    }

    private void criarCarros() { //adicionar Carros à lista
        if (carros == null) {
            carros = new ArrayList<Carro>();

            carros.add(new Carro("Focus", "Ford", 2016));
            carros.add(new Carro("Linea", "Fiat", 2014));
            carros.add(new Carro("Jetta", "Volkswagen", 2015));
            carros.add(new Carro("Cruze", "Chevrolet", 2017));
        }
    }

    public List<Carro> getCarros() {
        return carros;
    }

}