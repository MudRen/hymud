//Cracked by Roath
 
inherit NPC;
string ask_hanshan();
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("��������", ({"faming zhanglao","monk", "faming","zhanglao"}));
        set("long",
                "���������ǻ����µ����֣���ɫׯ�أ���ֹ������һ�����ǡ�
��˵����һ�����գ�Ҳ�ܺ��绽�꣬ȴ������������ĺ��С�\n");
   set("title", "����");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 55);
        set("per", 23);
        set("max_qi", 900);
        set("max_jing", 600);
        set("neili", 500);
        set("max_neili", 500);
        set("force_factor", 40);
        set("max_neili", 500);
        set("neili", 900);
        set("mana_factor", 30);
        set("combat_exp", 200000);
	set("combat_exp",200000);	
        set("shen_type", 1);

        set("eff_dx", 90000);
        set("nkgain", 300);


     
        set("inquiry", ([
                "Ѫ��": (: ask_hanshan :),
                "����": (: ask_hanshan :),
                ]));
        set("count",1);
        setup();
        initlvl((200+random(100)),1);
        carry_object("/d/obj/cloth/monkcloth")->wear();
}

string ask_hanshan()
{
        object ob=this_player();
        object me=this_object();
        object xueshu,hanshan;
       

        if (query("count") < 1)
                return "�����Ѿ�û���ˡ�";
//�ж��Ƿ�dntg over by dragon
        if( ob->query("obstacle/jz") == "done" )
        {
        command("shake");
        return("ƶɮ��֪��");
        }
       
        if( present("xue shu", ob) || present("han shan", ob) )
        return("�㲻������");

        xueshu = new("/d/qujing/jz/obj/xueshu");
        hanshan = new("/d/qujing/jz/obj/hanshan");
        switch ( random(2) ) {
        case 0:
        xueshu->move(ob);
        break;
        case 1:
        hanshan->move(ob);
        break;
        }  
      add("count",-1);
      return("���ǵ�����������Ϸ��ֵģ�����ȥ�ɡ�");
}        
        
        
