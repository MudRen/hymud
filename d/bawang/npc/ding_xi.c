 inherit NPC;
#include <ansi.h> 
void init();
int do_killing(string);
int accept_object(object,object);
void create()
{
        set_name("��ϲ", ({ "ding xi", "xi","dingxi" }) );
        set("gender", "����" );
        set("title", HIG "��ϲȵ"NOR);
        set("age", 20);
        set("int", 30);
        set("per", 30);
        set("class","wolfmount");
        if (random(3)) set("attitude","friendly");
        set("long",
                "�����Ǻ���ͣ������š�������Ǵ������ŵ�΢Ц��\n�������ǳ���������ϲ���Ķ�ϲ�����ߡ������Ķ�ϲ��\n"
                );
        set("max_neili", 2000);
        set("force", 2000);
        set("force_factor", 50);
        set("cor",200);
        set("combat_exp", 3000000);
        set("score", 90000);
        set("resistance/kee",40);
        set("resistance/gin",40+random(50));
        set("resistance/sen",40);
        
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
        carry_object(__DIR__"obj/shortsword")->wield();
} 
void init()
{
        add_action("do_killing", "kill");
        ::init();
} 
int do_killing(string arg)
{
        object player, victim;
        string name;
        player = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "������")
                {
                        message_vision("$N����ص������������ǲ����ֲ����ˡ���\n", this_object());
                        this_object()->kill_ob(player);
                        player->kill_ob(this_object());
                        return 1;
                }
                else if((string)name == "�鶫��")
                {
                        if(!player->query("m_success/ɱ�鶫��"))
                        {
/*                              message_vision( HIM "�������ʯ��һ˲������ǰһ����ֻ���鶫���Ŀڴ��Ѿ�����һ��Ѫ���� 
�鶫��Ŀ�ɿڴ��ؿ����Լ����˿ڣ��ֿ��˿���ϲ����������ÿ������......��
��δ�������ѵ��ڵ��ϡ�
ԭ����$N�ù鶫������֮�ʣ���֪����ʲô�ַ������������\n"NOR,this_object());
                           victim->die();          */
// adjusted by silencer, let player ����һ���Ͷ�����Ҫ��ȫ�ö�ϲ���͡�                          
                        message_vision( HIM "�������ʯ��һ˲������ǰһ����ֻ���鶫����ڴ��Ѿ�����һ��Ѫ���� 
�鶫��Ŀ�ɿڴ��ؿ����Լ����˿ڣ��ֿ��˿���ϲ����������ÿ������......��
��δ��������ҡҡ��׹��
ԭ����$N�ù鶫������֮�ʣ���֪����ʲô�ַ�������������\n"NOR,this_object());    
                                victim->set("qi",victim->query("max_qi")/2);
                                victim->set("eff_qi",victim->query("qi"));
                                player->add("score",100);
                                player->add("combat_exp",500);
                                player->set("m_success/ɱ�鶫��",1);
                        }
                }
        }
        return 0;               
}
