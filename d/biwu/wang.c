// wang.c ������
// By Lgg,1998.10

#include <ansi.h>

inherit NPC;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
        set_name("������", ({"wang chongyang", "wang"}));
        set("gender", "����");
        set("age", 66);
        set("class", "taoist");
        set("nickname",HIW"������"NOR);
        set("long",
                "������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ������������ˡ�������Ʈ\n"
                "Ʈ�����ۻ��䣬üĿ��񳣬����Щ�ɷ���ǵ�ζ����������һ\n"
                "ǻ��Ѫ����Ч���������������ϧ��͢���ܣ������Ļ����䣬\n"
                "�ִӵ��¾����������������Ĵ�����ִ�ȫ��̡�\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 145);
        set("int", 145);
        set("con", 145);
        set("dex", 145);

    

        set("combat_exp", 62000000);
        set("score", 500000);
   set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
 (: exert_function, "hup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.tonggui" :),                
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "unarmed.kong" :),
                (: perform_action, "unarmed.luanwu" :),                	
                (: perform_action, "unarmed.quan" :), 	
                (: perform_action, "unarmed.ming" :), 		
                (: perform_action, "unarmed.ruo" :),                	                	

                (: perform_action, "unarmed.dang" :),
                (: perform_action, "unarmed.shen" :),                	
                (: perform_action, "unarmed.fen" :), 	
                (: perform_action, "unarmed.hun" :), 		
                (: perform_action, "unarmed.jian" :),                	                	

                (: exert_function, "shield" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "powerup" :),                     
    
        }));

        set("qi", 369500);
        set("max_qi", 369500);
        set("jing", 365500);
        set("max_jing",365500);
        set("neili", 369000);
        set("max_neili", 369000);
        set("jiali", 100);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2200);
        set("combat_exp", 9600000);
        set("score", 500000);
		set_skill("kongming-quan", 1100);
	set_skill("kurong-changong", 1100);
        set_skill("finger", 1150);
        set_skill("yiyang-zhi", 1000);
        set_skill("force", 1000);
        set_skill("xiantian-qigong", 1000);    //��������
        set_skill("sword", 1000);
        set_skill("quanzhen-jian",1000);  //ȫ�潣
        set_skill("dodge", 1000);
        set_skill("jinyan-gong", 1000);   //���㹦
        set_skill("parry", 1000);
        set_skill("unarmed",1100);
        set_skill("haotian-zhang", 1000);    //�����
        set_skill("array",1100);
        set_skill("qixing-array",1100);
        set_skill("literate",1120);
        set_skill("strike",1150);
        set_skill("taoism",1140);
        set_skill("finger",1100);
        set_skill("sun-finger",1100);  //һ��ָ
        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xiantian-qigong");
        map_skill("strike", "haotian-zhang");
        map_skill("finger","sun-finger");
        map_skill("unarmed","kongming-quan");
if (random(2)==0)	        map_skill("unarmed","xiantian-qigong");

        create_family("ȫ���", 1, "�ƽ�");


        setup();

    carry_object("/p/item/ritemtz3/wsword24")->wield();
    carry_object("/p/item/ritemtz3/ahands11")->wear();
        carry_object(__DIR__"obj/greenrobe")->wear();

}
