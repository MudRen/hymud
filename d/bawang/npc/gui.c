 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("�鶫��", ({ "gui", "gui dong jing"}) );
        set("nickname", RED "���Ǹ���"NOR);
        set("gender", "����" );
        set("age", 44);
        set("per", 25);
        set("int",50);
        set("str",40);
        set("attitude","friendly");
        set("max_neili", 1500);
        set("force", 1500);
        set("force_factor", 90);
        
        set("reward_npc", 1);
        set("difficulty", 5);
        set("long",
                "һ�ŷ���������������ȴ�ܷḻ�������ִ����ܣ�ȴ���ǹεúܸɾ���\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
"�鶫������ص�������ϲ���Ϸ��Ѿ��ش����ﳤ�࣬�˶���Ҳ������
�Ľ����������ڣ����С椣�Ҳ�䵽�ҵ�����....������˲��书��
Ҫ��Ը����Ϸ�Я�֣��Ǻ�....�ư����֣�ָ�տɴ�������\n",
        }) );
        set("combat_exp", 3500000);
        
     set_skill("strike",270);
        set_skill("finger",270);
        set_skill("dodge",280);
        set_skill("force", 270);
	set_skill("canhe-zhi", 300);
	set_skill("murong-jianfa",250);       
        set_skill("shenyuan-gong", 250);
	set_skill("yanling-shenfa", 250);   
	set_skill("xingyi-zhang",280);
        set_skill("douzhuan-xingyi", 280);
	set_skill("parry", 280);
	set_skill("sword", 260);
	set_skill("literate", 280);
        set_skill("murong-daofa", 280);
        set_skill("blade",260);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");
         map_skill("strike", "xingyi-zhang");
	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
 		(: command("unwield sword") :),
		(: command("wield sword") :),           
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{
        object me;
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_killing","kill");
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() ) return;
        if((string)me->name() != "��ɽ��")
        {
                message_vision("$Nһ��$n�����ȵ�����ʲô�ˣ������Ҵ���կ����������������\n",this_object(),me);
                this_object()->kill_ob(me);
                me->kill_ob(this_object());
        }
        else
        {
                message_vision("$NЦ��������ɽ���������ռ����ɷ񣿴�������λС��������\nһ��������Ʒ��������ա���\n",this_object(),me);      
                message_vision("$Nתͷ����������Ц��������С椣����ż�......������\n",this_object(),me);                
        }
} 
int do_killing(string arg)
{
        object me,victim;
        string name;
   me = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "�鶫��"&&(string)me->name() == "��ɽ��"&&!me->query("m_success/ɱ�鶫��") )
                {
                        message_vision("$N��ʧɫ�������㲻����ɽ������$n��ͻȻ����ʹ$N¶���˶ദ������\n",this_object(),me);
                }
                else
                {
                        this_object()->kill_ob(me);
                        me->kill_ob(this_object());
                }
        }
} 
