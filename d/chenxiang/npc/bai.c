 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����", ({ "bai yujing", "bai", "yujing" }) );
        set("nickname", HIC"����"NOR);
        set("title", "��������");
        set("gender", "����" );
        set("age", 24);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 20);
        set("attitude","peaceful");
        set("max_neili", 1000);
        set("force", 1000);
        set_temp("apply/damage",150);
        set_temp("apply/attack",200);
        set("force_factor", 50);
        set("long",
                "���ϰ��񾩣���ѥ�ӣ��ɽ��ʣ�������һ��ո�µ��·���\n"
        );
        set("combat_exp", 4000000);
        set("score", 200000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����Ȼ��̾һ����ĬȻ���\n"      
        }) );
        set("inquiry",([
        "Ԭ��ϼ"  :"Ԭ���ﾹ����������ĺ������ۣ���Ϊʲôƭ�ң�\n",
        "yuan"  :"Ԭ���ﾹ����������ĺ������ۣ���Ϊʲôƭ�ң�\n",
        "������"  :"���������˸��Ҷ����ᷢ�ܳ��������յĳ��������Ѳ�֪����η�������ܡ���\n",
        "sword"  :"���������˸��Ҷ����ᷢ�ܳ��������յĳ��������Ѳ�֪����η�������ܡ���\n",
                ]) ); 
        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("unarmed", 80);
   set_skill("bai-quan",80);
        set_skill("literate", 100);
        set_skill("sword",130);
        set_skill("qingpingsword",150);
        set_skill("qingpingforce",120);
        set_skill("chaos-steps",120);
        map_skill("force", "qingpingforce");
        map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps"); 
        map_skill("unarmed","bai-quan"); 
        setup();
        carry_object("/d/chenxiang/npc/obj/newcloth")->wear();
        carry_object("/d/chenxiang/npc/obj/oldboots")->wear();
} 
void init()
{
        object me;
        ::init();      
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) 
        {
                call_out("greeting", 1, me);
        }
} 
int accept_object(object me, object obj)
{
        object bai, ob, sword;
        bai = this_object();
        if( (string) obj->query("name") == "��ȸͼ" && obj->query("real"))
        {
                environment(me)->answer_notify(bai,0);
        message_vision(HIY "\n$N��$n��������Ϊ��һ�ſ�ȸͼ��������թ���˼�ɻ��������ڣ�\n��ɷ��֪��Ԭ���﾿���ǰ��һ��Ǻ��ң���answer love/hate��\n"NOR, this_object(), me);
                return 1;
        }
        else if( (string) obj->query("name") == HIG "������"NOR )
        {
        message_vision(HIW "\n$N������˫�֣���������ӹ�������������ͨ��һ����ˤ���ڵأ�����Ҳ�䵽���ϡ�\n��������ͣ������Լ��ı������ò����ˡ�\n"NOR, this_object());
                ob = present("floor", environment(this_object()));
                sword = new("/d/tieflag/obj/csword");
           sword->move(ob);
                return 1;
        }
        else
        {
                tell_object(me,"����˵�����ⲻ������Ҫ�ġ�\n");
                return 0;
        }
}    
