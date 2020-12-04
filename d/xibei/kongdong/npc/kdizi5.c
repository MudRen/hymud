inherit NPC;


void create()
{
        set_name("�ջ�С��ʿ", ({ "shaohuo daoshi","daoshi" }) );
        set("title","��ἵ���");
        set("gender", "����" );
        set("class","taoist");
        set("age",16);
	create_family("�����", 2, "����");
	   set("combat_exp", 1000000);
        set("str", 55);
        set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",5000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("jinshe-jian",380);
set_skill("liancheng-jian",380);
set_skill("hujia-daofa",380);
set_skill("demon-strike",380);
set_skill("nine-moon-claw",380);
set_skill("ill-quan",380);
set_skill("doomstrike",380);
set_skill("luoriquan",380);
set_skill("qinnashou",380);
set_skill("taixuan-gong",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",380);
        set_skill("demon-blade",280);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
        set_skill("fengyu-piaoxiang",390);

        map_skill("unarmed","changquan");
        map_skill("sword","jinshe-jian");
        map_skill("force","taixuan-gong");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","liancheng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hun" :),
                (: exert_function, "jing" :),
                (: exert_function, "po" :),
                (: exert_function, "taixuan" :),		
                (: exert_function, "xuan" :),			
                (: perform_action, "unarmed.yuhuan" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.wan" :),
                (: perform_action, "sword.kun" :),	
                (: perform_action, "sword.shi" :),	
                (: perform_action, "sword.suo" :),	                	
                (: perform_action, "parry.ci" :),
                (: perform_action, "parry.erguang" :),
(: perform_action, "parry.gan" :),
(: perform_action, "parry.qian" :),
(: perform_action, "parry.qu" :),		             
(: perform_action, "parry.zhai" :),		             
(: perform_action, "parry.zhu" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );
	set("food_apply",15);
        setup();
        carry_object(__DIR__"obj/cloth3")->wear();
}

void init()
{
        object ob;
        if(interactive(ob=this_player()) && !is_fighting()){
		remove_call_out("show_msg");
            call_out("show_msg",1,ob);
            }
        add_action("do_yao","yao");
}

void show_msg(object ob)
{
        if(!ob||!present(ob,environment(this_object())))return;
        say("�⼸��С��ʿ����æ���ҵ�����������û��ע�⵽�㡣\n");
}
int do_yao()
{
    object who = this_player();
    object me = this_object();

    if( who->query("family/family_name")!="�����" || query("food_apply") < 0 )
        {
               message_vision("С��ʿ����$Nҡ��ҡͷ˵����λʩ����ʵ�ڶԲ���\n"
                        "ի����û�����ã�������һ�����\n",who);  
               return 1;
        }
    if ( (who->query("water") >= who->max_water_capacity()/2)
        &&(who->query("food") >= who->max_food_capacity()/2) ){
        return notify_fail("��Եñ����ģ��ȵ�������������ʲô�ң���\n");
        }

    message_vision("$N���Ŷ��ӿ�������ö�$n˵��\n"
        "��Сʦ�֣�����ʣ����ʵ���Ƕ��ò����ˡ���\n\n",who,me);
        printf("С��ʿæ˵����λ%s������û�ã������Ҹ���㶫���伢�ɡ�\n",
                (who->query("gender")=="����") ? "ʦ��" : "ʦ��" );
    who->set("food" ,who->max_food_capacity());
    who->set("water",who->max_water_capacity());

    return 1;
}

int accept_object(object who, object ob)
{
        if(ob->value() >= 1000)
        {
                message_vision("С��ʿ���ɵؿ���"+ob->name()+"����������ţ�\n"
                "����ô����˼�أ�\n",who);
                message_vision("С��ʿ�����룬��ʳ�����ø�$Nһ���ر���һ����"
                        "«��\n˵��Ҫ����������ɱ�˵�����ø���ġ�\n",who);
                message_vision("С��ʿת����ȥ����������\n",who);
                new(__DIR__"obj/subing")->move(who);
                new(__DIR__"obj/hulu")->move(who);
                return 1;
        }
        else 
        {
                message_vision("С��ʿҡҡͷ��ʦ��˵�����������Ҫ���˵Ķ�����\n",who);
                return 0;
        }
}

                
