#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name(HIY "��̫��" NOR, ({ "empress","queen"}));
        set("shen_type", 0);
        set("age",43);
        set("gender", "Ů��");
      set("per",24);
        set("long",
                "�����ð������֣�Ҳ�������겻�����⣬����������ɫ�Եúܲ԰ס�\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "�ݺ�" : "��ʲô��˼......��\n",
                "Ӫ��" : (: ask_me :),
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book7")!=3))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл����֮����\n",this_object(),who);
	message_vision("$N��$n˵���� ��������ı���棬�治֪������Ǻ� ��\n",this_object(),who);
if(((int)who->query("jinyong/book7")==3))
{	
	i = 300+random(800);
	who->set("jinyong/book7",4);
	who->add("combat_exp",i+9880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
}
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N˵�������������ʧ������......\n"NOR,ob);
destruct(this_object());
   return;      
}