
// young.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����Ů��", ({ "young" }) );
	set("long", "�������Ů�Ӳ�֪������˭, �������ǻ��ڽ�ͷ�������ڵȴ�ʲô��\n");
      set("gender", "Ů��" );
	set("age", 22);
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
      set("combat_exp", 5000);
      set("score", 1000);
      set_skill("dodge", 70);
      set_skill("snowwhip", 60); 
      set("force", 300);
      set("max_force", 300);
      set("force_factor", 10);
      set("chat_chance",16);
      set("chat_msg",({
              (: this_object(), "random_move" :),
      }));
        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
        (: this_object(),"random_move" :),
        (:command("say �ѵ��㲻������Ǵ����") :),
         }) );

      setup();
      carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object me, object ob)
{
        object obb;
        int amount;
        amount = 5000;
        if(!ob->query("���ݳǹٱ�����") ) return 0;
        say("������!�����....\n");
        tell_object(me,"СŮ������Ϊ������50�����ӻ�����������\n");
        message_vision("����Ů�Ӹ�$N50������.\n",me);
        obb=new(SILVER_OB);
        obb->set_amount(amount/100);
        obb->move(me);
        call_out("dest_obj",0);
	return 1;
}

int dest_obj()
{
        object letter;
        letter=present("letter",this_object());
if(letter)
        destruct(letter);
        return 1;
}

