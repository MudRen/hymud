 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack();  
void create()
{
        set_name("���໪", ({ "li ehua" }) );
        set("gender", "Ů��");
        set("age", 25);
        set("title",HIY"��������"NOR);
        set("nickname",HIG"���ڽ���"NOR);
        set("long",
"һ����������Ů�����Ű��£�ӭ�����������һ���������������ᡣ
�ഫ���������������۵Ĺ��ŵ��ӣ�һ��̫�����������޵У���Ƿֻ
�ǻ����ѡ�˫����赣��������˵���ɵ��ߴ����������Ͻ��ݡ�����
�������Ŵ�ѩ������������ý���֮�������ſ�˼���գ���Ի�����似
�ۣ�������и�ɻ���Ψ��ƾ���������������������\n\n"
);
          
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty",1);
        set("class","wudang");
        
        set("combat_exp", 1600000);        
        set("int", 30);
        set("cps", 60);
        set("spi", 30);
        set("fle",50);
        set("per",40);
        set("str",40);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
     set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        carry_object(__DIR__"obj/heavysword")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 
void init()
{
        object ob;
        ::init();
        add_action("do_killing","kill");
} 
int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen; 
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "li zhihua" && player->query("combat_exp")>3400000)
        {
            message_vision(
"$N߳����ǿ������,��������,�����ǽ���\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
} 
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {       who->cast_spell("zombie-bolt");
                        return;
           }               
        }
        who->smart_attack();
        return;
} 
smart_attack() {
        if (this_object()->query_temp("weapon"))
                this_object()->perform_action("sword.chanzijue");       
                else this_object()->perform_action("unarmed.nianzijue");        
        return;
        } 
