 //by xiaolang
// ����¥ɱ�� 
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�����", ({ "liu yuhen" }) );
        set("gender", "����" );
        set("title",HIG"�����ɾ�"NOR);
        set("nickname",WHT"�����Թſ���ޣ��������޲�����"NOR);
        set("age", 27);
        set("class","swordsuper");
        set("libie/���_β��",1);
        set("str", 60);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
�����������ѱ�����ȥ��һ�룬�˿������Ѹɱ����������ı���
���۾�������бб�ĳ��˹���������һ�����ӣ��ǰ����Ҳ����һ
˫�۾�����һֻ������������ֻʣ����һ���ֺ�����Ķ�����Ǳ�
���õ��滮�˸���ʮ���֣�˫��Ҳ�����󿳶��ˣ�����������װ��
������������������
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 ); 
        set("combat_exp", 40000000); 
        set("chat_chance", 1);
        set("chat_msg", ({
"�������Ȼ���ˣ��������Թſ���ޣ��������޲����ᣬ���ڡ������ɾ���\n�������ˣ�ֻ�ɺ�����޻����ţ�ʮ��ǰ�����Ҳ���������ˣ�\n����ƫƫֱ�����ڻ����ţ��Ҵ�������һ�����ѡ���"
        }) );  
        set("neili",5000);
        set("max_qi",50000);
        set("max_jing",30000);
        set("max_jing",30000);
        set("qi",50000);
        set("jing",30000);
        set("jing",30000);
    set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

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

        setup();
        carry_object(__DIR__"obj/hook")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message("vision",
                HIW + name() + "̾��̾����һ������ʧ����Ӱ���١�\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}  
void init()
{
    object ob;
    ::init();
    set_temp("libieforce_libie",1);
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
} 
void greeting(object ob)
{   
        string where, location;
        if( !interactive(ob) || environment(ob) != environment() )
                return;
   if (!ob->query_temp("����¥/lou1a") ){
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}    
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("����¥/lou1a",1);
        ::die();
}  
