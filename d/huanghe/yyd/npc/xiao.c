// xiao.c �����
// zly 99.6.11

#include <ansi.h>

inherit NPC;
int ask_me();
void create()
{
        set_name("�����", ({"xiao banhe", "banhe", "xiao"}));
        set("gender", "����");
        set("title", HIY"��������"NOR);
        set("shen_type", 1);
        set("age", 50);
        set("long", 
"���������֪���Ľ�����������ͣ���������ΰ��������룬����
��ӣ��������䡣\n"
        );
        
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

       set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 380);           // �л�����
	set_skill("checking", 380);          // ����;˵
	set_skill("training", 380);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        set("chat_chance", 3);
        set("chat_msg", ({
            "��������һ����˵������������Щ�����ӱ����õ�ԧ�쵶����\n",
            "�����̾��һ������˵�����������Ů��ѽ�����ǵ�Ƥ����֪����һ���ܲ��ܸĸġ���\n", 
        }) );

        set("inquiry", ([
        "ԧ�쵶" : (: ask_me :),
        "���л�" : "�����ҵĹ�Ů�������������������أ�˵�꣬�Ǻǵ�Ц��������\n",
        "Ԭ����" : "�����ҵĹ�Ů����˵�꣬¶�������Ц�ݡ�\n",
        "̫������" : "�������ڰ�æ���ź�ɽ�أ�����ʲô������\n",
        ]));

        setup();
        carry_object(__DIR__"obj/changpao")->wear();        
        add_money("gold",2);
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

	  if(((int)who->query("jinyong/book14")!=4))
	{
		message_vision("$N��$n˵���� ԧ�쵶�����������ܣ�\n",this_object(),who);
		return 1;	
	}
	  	if(!who->query_temp("book145"))
	{
		message_vision("$N��$n˵���� ����ȥ��Ԭ���аɣ�\n",this_object(),who);
		return 1;	
	}

	if ( !objectp(present("yuanyang dao", who)) )
{
		message_vision("$N��$n˵���� ����ԧ�챦����\n",this_object(),who);
		return 1;

}	

	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� ԧ�쵶�����ܾ��������޵С�\n",this_object(),who);

	
	i = 500+random(2800);
	who->set("jinyong/book14",5);
	who->add("combat_exp",i+16880);
	who->add("potential",i*28);
	who->add("mpgx",20);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+16880)+"�㾭��"+
	           chinese_number(i*28)+"��Ǳ��"+"��ʮ�����ɹ��� ����ɳ����ޣ���\n");
message("channel:chat", HIB"������III����˵"+who->name() + "�����ԧ�쵶����������!"NOR"\n", users());

	who->save();
	call_out("destroying", 0);                       
	return 1;
}