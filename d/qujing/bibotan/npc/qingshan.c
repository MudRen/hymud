inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("Ц������", ({"xiaoboer tian", "tian"}));
        set("long", "������ʯɽ�̲�̶��С����\n");
        set("age", 30);
	set("title", "������");
        set("attitude", "friendly");
        set("gender", "����");
	set("class", "dragon");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",1000);
        set("max_jing", 1000);
        set("combat_exp", 350000);
  set("combat_exp", 450000);

 
set("inquiry", ([
"��԰": "��˵���԰�Ǹ������󣬲�֪����λ�ģ��ٺ٣�����\n",
]) );

        setup();
        initlvl((500+random(500)),54);
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
	if( random(5) > 3  ) {
        if (objectp(present("xiao", environment(this_object())))) {
                switch( random(6) ){
                        case 0:
                                command("say �첨��Ц������˯���ˣ�");
                                command("wake xiao");
                        break;
                        case 1:
                                command("say �첨��Ц����˵�����������ˡ�");
                                command("consider xiao");
                        break;
                        case 2:
                                command("say �첨��Ц�������أ�");
                                command("poke xiao");
                        break;
                        case 3:
                                command("say �첨��Ц�����������Ǹ�С������Ư����");
                                command("grin xiao");
                        break;
                        case 4:
                                command("say �첨��Ц���������ţ����������ȥ��");
                                command("kick xiao");
                        break; 
			case 5:
				command("say �첨��Ц����ȥ������ʾ��λ��");
				command("lazy xiao");
			break;
                	}
        	}
        }
	}
        return ::heal_up() + 1;
}

�