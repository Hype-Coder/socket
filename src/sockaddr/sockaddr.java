package sockaddr;

import arrays.CharArray;
import primitives.ShortInt;
import template.InvalidArgument;
import template.Structure;
import template.Var;

public class sockaddr extends Structure {


    public sockaddr() throws InvalidArgument {

        super();

    }

    public sockaddr(ShortInt sa_family, CharArray sa_data) throws InvalidArgument {

        super();

        this.setVar("sa_family", sa_family);

        this.setVar("sa_data", sa_data);

    }

    @Override
    protected Var[] setVar() throws InvalidArgument {

        return new Var[]{

                new Var("sa_family", new ShortInt()),

                new Var("sa_data", new CharArray(14))

        };
    }

}
