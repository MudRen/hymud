#include <ansi.h>

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_move", "move");
}

void create()
{
       set_name("����", ({"haigu","skeleton"}) );
       set_weight(10000);
       set_max_encumbrance(6000000);
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "��");
       set("long", "�⸱�������������Ѿ��ܾ��ˡ�\n");
       set("value", 0);
       set("material","wood");
       set("no_get",1);
       set("init",0);
       }
       setup();
}

int do_move(string arg)
{
        int i;
        object book;
        object fang,who;
        object me = this_player();
        who=me;
        if (!id(arg))
                return 0;
        if (this_player()->query_temp("wumu_shanshui") ) {
                if (!present("wumu yishu",me)){


 if ((int)who->query("jinyong/book5")==7 && !query("iskillok"))
        {
      	fang = load_object("/d/tiezhang/npc/qqzhang");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object("/d/tiezhang/npc/qqren");
	fang->move(environment(who));	
	fang->kill_ob(who);

     this_object()->set("iskillok",1);
     set("iskillok",1);
 message_vision(
HIY"$N�����Ų�����ǣ�����������һ���飬$N������𴧵����С�\n"NOR
RED"����ͻȻ�����������ָ��������飬����$Nһ����\n"NOR,this_player());
return 0;
}

 if ((int)who->query("jinyong/book5")==7 && !query("iskillok"))
        {
      	fang = load_object("/d/tiezhangy/npc/qqzhang");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object("/d/tiezhangy/npc/qqren");
	fang->move(environment(who));	
	fang->kill_ob(who);

     this_object()->set("iskillok",1);
     set("iskillok",1);
 message_vision(
HIY"$N�����Ų�����ǣ�����������һ���飬$N������𴧵����С�\n"NOR
RED"����ͻȻ�����������ָ��������飬����$Nһ����\n"NOR,this_player());
return 0;
}

 if (!who->query_temp("book581"))
        {
 message_vision(
HIY"$N�����Ų�����ǣ������ֺ�������ʲôҲû���ˡ�\n"NOR,this_player());
return 0;
}
 if (!who->query_temp("book582"))
        {
 message_vision(
HIY"$N�����Ų�����ǣ������ֺ�������ʲôҲû���ˡ�\n"NOR,this_player());
return 0;
}



                message_vision(
HIY"$N�����Ų�����ǣ�����������һ���飬$N��æ���𴧵����С�\n"NOR
RED"�Ǻ���ͻȻӭͷ��$N�˽�������ˤ�ڵ��ϣ�����ɢ��������$Nһ����\n"NOR,this_player());
                book = new(__DIR__"wumu-yishu");
                book->move(me);

if ((int)who->query("jinyong/book5")==7){   	

                        		i = 900+random(2000);
		who->set("jinyong/book5",8);
		who->add("combat_exp",i+17000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		
		tell_object (who,"��Ӯ����"+chinese_number(i+17000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
   }

                destruct(this_object());
                return 1;
                }
                message_vision(
HIM"���Ǽ������鶼�õ��˻��������û�°�����Ų��Ųȥ�ĸ�ʲô������\n"NOR, this_player());
                return 1;
                }
                else {
                message_vision(
HIR"$N�����Ų�����ǣ�ͻȻ�Ӻ��ǵ�����ð��һ�ɶ��������$N�ı����С�\n"NOR, this_player());
		me->set_temp("last_damage_from", "�ж�");
                me->die();
                return 1;
        }
}
