#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create() 
{
    set_name("��÷��ʦ", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��
\n"
        );
    set("nickname", HIW "���ɹ�" NOR);
    set("gender", "Ů��");
    create_family("��ɽ��", 16, "����");
    set("student_title","����");
    set("age", 59);  
    set("str", 25);
    set("int", 30);
    set("con", 25);
    set("qi", 50000);
    set("max_qi", 50000);
    set("jing", 2000);
    set("max_jing", 2000);
    set("neili", 9000);
    set("max_neili", 9000);
	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangjian")->wield(); 
} 
void init()
{
    object ob;
    ob=this_player();
   if ((int)ob->query("marks/killed_yuan")==1 )
       {
           ob->delete("marks/killed_yuan");
           kill_ob(ob);
       }
}
void attempt_apprentice(object ob)
{
        if (ob->query_skill("sword",1) < 100) {
         command("say  ��Խ�����֪���٣���Ȼ�������ң�");
                return;
    }
    if ((int)ob->query_skill("dodge",1) < 100 ) {
        command("say ���µ����ƺ�����ѧ�䰡��");
                return;
    }
    if( (int) ob->query("marks/ɱ������") == 1 )
     { 
    command("smile");
    command("recruit " + ob->query("id"));
    ob->delete("marks/ɱ������");
     }
     else   
     command("say �����ڴ����ϳ�ҵ����ֻ࣬��һ�˻ỵ�ҵĴ���...");
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}    
