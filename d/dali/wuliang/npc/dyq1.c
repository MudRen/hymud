// cool980310
// ������
// cool980724
// Modify By River 98/12
inherit NPC;

void create()
{
        set_name("������", ({ "duan yanqing", "duan","yanqing"}) );
        set("nickname", "�����ӯ");
	set("title", "�Ĵ����");
        set("gender", "����" );
        set("age", 52);
        set("str", 26);
        set("con", 23);
        set("dex", 5);
        set("int", 25);
        set("per", 10);
   	set("attitude", "friendly");

        set("max_qi", 35000);
        set("max_jing", 30000);
        set("eff_jingli", 30000);
        set("neili", 40000);
	set("qi", 35000);	
        set("max_neili", 40000);
        set("jiali", 100);         
        
        set("long","�����Ǹ����ߣ����봹�أ���Ŀ��ڡ�\n");
        set("combat_exp", 6500000);
        set("shen", -20000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat",({ 
           (: perform_action, "finger.sandie" :), 
          (: perform_action, "finger.dian" :), 
(: perform_action, "finger.dragon" :), 
(: perform_action, "finger.jian" :),            
(: perform_action, "finger.qian" :),            
(: perform_action, "finger.sandie" :),            
        }));
        set_skill("parry", 280);
        set_skill("dodge", 260);
        set_skill("force", 280);
        set_skill("finger", 260);
        set_skill("buddhism", 200);
        set_skill("literate", 220);
        set_skill("sword", 230);
        set_skill("duanjia-sword", 320);
        set_skill("kurong-changong", 340);
        set_skill("yiyang-zhi", 360);
        set_skill("xiaoyaoyou", 350);
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        map_skill("force", "kurong-changong");
        prepare_skill("finger","yiyang-zhi");

        set("inquiry", ([
           "����" : "�ٺ٣������ҹ���ʯ������",
           "name" : "�Ϸ���Ƕ�����",
           "������" : "�Ϸ���Ƕ�����",
        ]) );

        setup();
        carry_object(__DIR__"obj/pao")->wear();
}

void init()
{       
        object me,ob;
        ob = this_player();
	me = this_object();
        ::init();
        if( interactive(ob)
         && ob->query_temp("kill")){
         call_out("kill_ob", 0, ob); 
         }
}
