#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "hong niangzi", "hong" }) );
        set("gender", "Ů��" );
        set("long",
         "�����Ϻ���Ҳ�ڷ��⣬һ�ֺ��ҫ�ۣ�������������Ĺ⡣��������\n�ϵ�Ȼ���ź��·������ⲻ�Ǵ����·��Ϸ������ģ���ʵ�ϳ����·�\n�⣬������ÿ���ط������ڷ��⣬�����������۾�������Ц��\n");
        set("nickname", HIR "�ȿ����"NOR);
        set("chat_chance",1);
        set("chat_msg", ({
        "�������۲��������������˸����ۣ���Ц��Ц�������ҳ�����������\n�������İ�����\n",
                                })  ); 
        set("combat_exp", 1000000);
        set("force",500);
        set("max_neili",500);
        set_temp("apply/damage",50);
        set("no_arrest",1);
        
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
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
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

        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
} 
void init()
{       
        object ob;
        ::init();
   if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) 
                return;
        message_vision(HIW"$N�۲����������$nһ�ۣ���Ц��Ц����������֪�����������ģ�\n��ô�������Լ�������������ҩ���ڷ�ͷ���Լ�ȥ�ðɡ���\n"NOR,this_object(),ob);
                
} 
