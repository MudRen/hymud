#include <ansi.h>
inherit NPC;
void smart_fight(); 
int stone();
int stone1();
int stone2();
int stone3();
int stone4();
int stone5(); 
void create()
{
        set_name("��СС", ({ "bad kid" }) );
        set("title",WHT"����ͯ��"NOR);
        set("gender", "����" );
        set("age", 1+ random(10));
        set("long", "���ͯ����İ�С��ȴ����һ�ų��˵���������������֮����\n");
        set("combat_exp", 3500000);
        set("class","shenshui");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("str",36);
        set("cor",40);
        set("no_busy",5);
        set("resistance/kee",30);
        set("resistance/gin",random(70));
        set("resistance/sen",50);
        
        set("atman",1200);
        set("max_atman",1200);
        set("mana",1000);
        set("max_mana",1200);
        set("force",1200);
        set("max_neili",1200);
        set("force_factor", 90);
        
        set("inquiry", ([
                "stone" : (: stone :),
                "�����ʯ" : (: stone :),
                "�������" : (: stone1:),
                "�̺�����" : (: stone2:),
           "��ڤ�Ͼ�" : (: stone3:),
                "�����൤" : (: stone4:),
                "��¶��ʯ" : (: stone5:),
                "��֮��" : (: stone1:),
                "��֮��" : (: stone2:),
                "��֮��" : (: stone3:),
                "ɳ֮��" : (: stone4:),
                "��֮��" : (: stone5:),
        ]));
        
                     
	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );

                
        setup();
        add_money("gold", random(5));
        carry_object("/clone/misc/cloth")->wear();
        if (!random(3)) carry_object(__DIR__"obj/hesan");
} 
smart_fight()
{
   int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie3");
                return;
        }
        return;
}    
int stone(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        message_vision(YEL"$N˵����̫��ʱ������ײ������Ĳ���ɽ��Ů��������ʯ�Բ����죬��
������������֮�ġ���֮�ǡ���֮�ơ�ɳ֮�ס���֮�۸����ռ�����ɫ��ʯ��
�������ʯ�ֱ��ǣ�������䡢�̺����ġ���ڤ�Ͼ��������൤����¶��ʯ��
��˵�κ�������ܵõ����е�һ�֣����ܴ��еõ������������������ \n"NOR,ob);
        message_vision(YEL"$N˵�����������д�������װס�������\n",ob);
        command("heihei");
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone1(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵������������ڴ�֮�ۣ����������ö��˶�֪���ˡ������� \n"NOR);
        tell_object(me,YEL"��СС˵�������ţ���������ʱ�Ǵ����ϵ������ģ���ʱȴ�����ڵ����ҡ���\n"NOR);
   me->delete_temp("badkid/bribe");
        return 1;
} 
int stone2(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵�����̺������ں�֮�ǣ�������������� \n"NOR);
        tell_object(me,YEL"��СС��������˭֪ʮ�������ᣬ�������黯Ѫ�ۡ���\n"NOR);
        tell_object(me,YEL"��СС˵��������������߻����ˣ����һ��Ǹ����ˡ���\n"NOR);
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone3(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵������ڤ�Ͼ��ڷ�֮�ƣ���֮�ƾ��Ƿ��ơ��� \n"NOR);
        tell_object(me,YEL"��СС˵����������������Խ�����Խ�ҾͲ��ɡ���\n"NOR);
        me->delete_temp("badkid/bribe");
        command("sigh");
        return 1;
} 
int stone4(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
           return 1;
        }
        tell_object(me,YEL"��СС˵���������൤��ɳ֮�ס��� \n"NOR);
        tell_object(me,YEL"��СС���ĵ�������͵������ڵ��µ������������������������ߵ��˶��죬��Ҫ
���ڵ���һ�������˾����Ժ��������죬���ų�������\n"NOR);
        me->delete_temp("badkid/bribe");
        return 1;
} 
int stone5(){
        object me,ob;
        ob= this_object();
        me=this_player();
        if (!me->query_temp("badkid/bribe",1)){
                message_vision(YEL"$N����$n�ƻ���Ц���������ſ�����$n�������¡�����\n"NOR,ob,me);
                message_vision(YEL"$N˵����������ɡ�������\n"NOR,ob);
                return 1;
        }
        tell_object(me,YEL"��СС˵������¶��ʯ����֮�ġ��� \n"NOR);
        tell_object(me,YEL"��СС˵���������֮��ָ������·�������ҵǻ�ɽ���η��ƣ��������⣬����
��Դ������������ҹ����󹦿�һ���Ǹ������ѽ��������\n"NOR);
        me->delete_temp("badkid/bribe");
        command("hit");
        return 1;
}  
int accept_object(object who, object ob)
{
        if (ob->value()>=100000) {
                command("giggle");
                command("say ��������ʰɡ�");
                who->set_temp("badkid/bribe",1);
                return 1;
        } 
        
        command("say ��ô�㡣������Ц�ɡ�");    
        return 0;
        
}     
