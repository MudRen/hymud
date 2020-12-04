#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({"wen liangyu", "liangyu","wen" }));
        set("nickname", HIC"ǫǫ����"NOR HIG"��������"NOR );
        set("gender", "����");
        set("age", 42);
        set("long",
                "���¸߹ڣ��������ţ�������ҡ��һ�����ȣ�����ȥ������ס�\n");
        set("attitude","friendly");
        create_family("��ɽ", 3, "��ͷ��");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("apprentice_available", 5);
        set("rank_nogen",1); 
        set("ranks",({ "С���","�����","СͷĿ","��ͷĿ","��ͷ��",RED"���"NOR,RED"��˧"NOR,HIR"��ɽ��"NOR }));       
        set("str", 50);
        set("int", 40);
        set("con", 26);
        set("agi", 50);
        set("per", 40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "̫��ʹ�����������������ǳ���������Ҿ������㡣�����㵽���ֺ��������� \n",
        }));
    set("max_neili", 20000);
    set("neili", 20000);
    set_temp("apply/damage", 100);
    set("force_factor", 100);
    set("combat_exp", 10000000);
        set("score", -50000);
     set("max_qi", 33500);
	set("max_jing", 31500);
	set("neili", 33000);
	set("max_neili", 33000);
	set("jiali", 150);

	set("combat_exp", 5900000);
	set("score", 800000);
    set_skill("cuff", 300);
    set_skill("strike", 100);
    set_skill("qingfu-shenfa", 100);
    set_skill("hanbing-mianzhang", 300);
    set_skill("sougu", 100);
    	set_skill("force", 360);
	set_skill("dodge", 340);
	set_skill("sword", 340);
	set_skill("blade", 340);
	set_skill("parry", 340);
	set_skill("cuff", 200);
	set_skill("blade", 240);
	set_skill("jinwu-daofa",240);
	set_skill("jiuyang-shengong", 260);
	set_skill("lingxu-bu", 240);
    	set_skill("damo-jian", 240);
    	set_skill("qishang-quan", 380);
    	set_skill("hunyuan-zhang", 250);
    	set_skill("literate", 200);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
    	map_skill("parry", "hunyuan-zhang");
    	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("cuff","qishang-quan");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 2660);
	set_temp("apply/armor", 2660);
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
		(: command("perform youyouhunduan") :),


	}) );
        setup();
        carry_object(__DIR__"obj/mask")->wear();
        carry_object(__DIR__"obj/silkcloth")->wear();
} 
void die()
{
        object me;
        object grass; 
        if(objectp(me = query_temp("last_damage_from")))
        {
                command("say �����Ҵ��⣬�ݻ���ɽ����֮���ӣ�\n");
                if(me->query_temp("marks/������̫ү")){
                        me->delete_temp("marks/������̫ү");
                        me->set("m_success/��ɽ���",1);
                }
                me->set("marks/ɱ̫��ʹ��",1);
                grass = new(__DIR__"obj/grass");
                grass->move(this_object());
                ::die();
        }
} 
void init()
{
        object me;
        ::init();      
        if( interactive(me = this_player()) && !is_fighting()) 
        {
                call_out("greeting", 1, me);
   }
        add_action("do_kill", "kill");
} 
int greeting(object me)
{
        object npc;
        object xiaoma;
        npc = this_object();
        if ( me->query_temp("marks/wolf_xiaoma_good") )
        {
                message_vision(HIY "$N��Ц�����ٺ٣��ֲ���С����ô��������ԭ�������˸����֣�����ʲô��\n"NOR, npc);
        }
        else
        {
                message_vision(HIY "$N����������������Ұɣ���������֣�\n"NOR, npc);
        }
        return 1; 
} 
int do_kill(string arg)
{
        object me,ob;
        me = this_player();
        ob = this_object();
        if (arg != "sun legate")
                return 0;
        else 
        {
                me->kill(ob);
                ob->kill(me);
                environment(me)->kill_notify(ob,0);
        }
        return 1;
}
void do_recruit(object me){
        if(me->query("title") == "��ɽ "+HIR"��ȴ���"NOR){
                command("say ���Ҿ�����Ϊͽ�ɡ�\n");
                command("recruit" + me->query("id"));
        } else {
                command("hmm");
        } 
} 
int recruit_apprentice(object ob){
        if( ::recruit_apprentice(ob) )
            ob->set("class", "wolfmount");
    add("apprentice_availavble", -1);    
} 

void reset(){
        set("apprentice_available", 5);
}
