#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
        set_name("��ƽ֮", ({ "lin pingzhi", "lin", "pingzhi" }));
        set("gender", "����");
        set("age", 18);
        set("title", "�����ھ�����ͷ");
        set("long", "�����ǡ������ھ֡�������ͷ������ƽ֮��\n");
        set("combat_exp", 300000);
        set("shen_type", 1);
        set("qi", 5000);
        set("max_qi", 5000);
        set("max_neili", 5000);
        set("neili", 5000);
        set("jiali", 10);
        set_skill("force", 150);
        set("per",25);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set("inquiry", ([
                "�����ھ�" : (: ask_me :),
        ]) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 200);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	object fang = present("fang renzhi",where);
	if(fang)
	{
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�����ȴ�����ǰ��λ�ɣ�\n",this_object(),who);
		return 1;
	}
	  	if(((int)who->query("jinyong/book8")>=2))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� С��һʱ�嶯���򱧲�ƽ��ɱ�������������׺��Ķ��ӡ�\n",this_object(),who);
	message_vision("������ɺ���ǰ��Ѱ�𣬸����ھ�ȫ�Ҽ�����Ȯ������\n",this_object());
	message_vision("�Ҹ���Ϊ��ס�ּ�Ѫ������ҹ���ҳ��ǣ������ֻ�а�ʦѧ�գ�ѧ���书��\n",this_object());
	message_vision("��ƽֻ֮Ҫ����һ�죬�ı��˳�\n",this_object());
	
	i = random(800);
	who->set("jinyong/book8",2);
	who->add("combat_exp",i+6880);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
	tell_object (who,"��Ӯ����"+chinese_number(i+6880)+"�㾭��"+
	           chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	return 1;
}
