package sockaddr;

import arrays.CharArray;
import primitives.Int;
import primitives.ShortInt;
import template.DataTypes;
import template.InvalidArgument;
import template.Structure;
import template.Var;

public final class sockaddr_in extends Structure {


    public sockaddr_in(ShortInt sin_family, ShortInt sin_port, in_addr in_addr, CharArray sin_zero) throws InvalidArgument {

        super();

        this.setVar("sin_family", sin_family);

        this.setVar("sin_port", sin_port);

        this.setVar("in_addr", in_addr);

        this.setVar("sin_zero", sin_zero);

    }


    public sockaddr_in() throws InvalidArgument {

        super();

    }

    @Override
    protected Var[] setVar() throws InvalidArgument {

        return new Var[]{

                new Var("sin_family", new ShortInt() ), // inizializzo i valori a 0, se li mettessi a null, la struttura non le considererebbe come variabili

                new Var("sin_port", new ShortInt() ),

                new Var("in_addr", new in_addr()),

                new Var("sin_zero", new CharArray(8))

        };

    }


    public static final class in_addr extends Structure {


        public in_addr(Int s_addr) throws InvalidArgument {

            super();

            this.setVar("s_addr",s_addr);

        }

        public in_addr() throws InvalidArgument {

            super();

        }

        @Override
        protected Var[] setVar() throws InvalidArgument {

            return new Var[]{

                    new Var("s_addr", new Int() )

            };

        }
    }

}
