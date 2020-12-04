// xiaofeng.c ����(�Ƿ�)

#include <ansi.h>

inherit NPC;
int ask_me();
void check_skills(object ob);
int waiting(object me, object dest);
int checking(object me, object dest);
int do_back(object me);
int do_kill(object me, object dest);

void create()
{
	set_name("����", ({"xiao feng", "xiao", "feng"}));
	set("gender", "����");
	set("nickname",HIB"���ƽ���"NOR);
	set("age", 28);
	set("long", 
		"������ؤ��ǰ�ΰ������򱻷����������˶��������롣\n"
		"�ڽ��������������Ľ�ٸ�����Ϊ�����Ƿ壬��Ľ�١���\n"
		"����һ����ͨ�Ĵֲ����ӣ�������һ���������һϵ��\n"
		"������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ\n"
		"�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"����̾�˿����������������벻�����������ж�����Ȼ�����������һ��Ů����ƭ��\n",
		"�����૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",

	}));

	        set("inquiry", ([
                "Ӫ��" : (: ask_me :),
        ]) );
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 120);             // �����ڹ�
	set_skill("huntian-qigong", 120);    // ��������
	set_skill("unarmed", 120);           // ����ȭ��
	set_skill("xianglong-zhang", 120);   // ����ʮ����
	set_skill("dodge", 120);      	     // ��������
	set_skill("xiaoyaoyou", 120);        // ��ң��
	set_skill("parry", 120);             // �����м�
	set_skill("begging", 50);            // �л�����
	set_skill("checking", 50);           // ����;˵
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}



int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);


	  	if(!who->query_temp("killtlbb10"))
	{
		message_vision("$N��$n˵���� ����������ô���ˣ� �ҶԲ�������㣬�����ٶԲ������ˡ�\n",this_object(),who);
		 
		return 1;	
	}


	  	if(((int)who->query("jinyong/book4")!=9))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}	

	  	if(((int)who->query("jinyong/book4")>=10))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	

	
	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� лл��λ�ֵܵĽ���֮����\n",this_object(),who);


	
	i = 1000+random(3800);
	who->set("jinyong/book4",10);
	who->add("combat_exp",i+26880);
	who->add("potential",i*28);
	who->add("mpgx",20);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+26880)+"�㾭��"+
	           chinese_number(i*28)+"��Ǳ��"+"��ʮ�����ɹ��� ����ɳ����ޣ���\n");
message("channel:chat", HIB"������III����˵"+who->name() + "����������˲�����������!"NOR"\n", users());
	who->save();
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