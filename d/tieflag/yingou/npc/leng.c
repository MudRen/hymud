 // garrison.c
#include <ansi.h> 
inherit NPC;
#define LOWER_LIMIT 20000
#define DUMP_PLACE  "/d/laowu/road0.c"
void create()
{
        set_name("����˪", ({ "leng", "lengruoshuang" }) );
        set("long",
"��λ������������������һ�ָ߲����ʣ�������˪�ĸо���
������̫��������̫�������ԣ������������ʶ��ʶ���������\n");
        set("attitude", "heroism");
        set("title", HIW "��ɽ"NOR);
        set("str", 20+random(10));
        set("cor", 26);
        set("gender", "Ů��");
        set("cps", 25);
        set("per", 30);
        set("age",19);
        set("combat_exp", 100000); 
        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100); 
        setup(); 
        carry_object(__DIR__"obj/goldcloth")->wear();
} 
void init()
{
        add_action("do_know","know");
} 
int do_know()
{
   object me;
        object dump;
        me = this_player();
        if((int) me->query("combat_exp") >= LOWER_LIMIT)
        {
        tell_object(me,"����˪̾�˿���������������ֻ���������������ˣ���\n");
        tell_object(me,"����˪���㲻�������ķ���һ�����˯Ѩ��\n");
        me->unconcious();
        me->set("marks/����˪", 1);
        me->save();
        dump = find_object(DUMP_PLACE);
        if (!dump) dump = load_object(DUMP_PLACE);
        if(dump) me->move(dump);
        }       
        else
        {
        if(me->query("gender") == "����")
message_vision("$N������������$n���Ǵ���⣬�������
�������������ֳ������Ҽ��ö��ˣ������㶼�е����ģ�������\n",this_object(),me);  
        else
message_vision("$N��$n����һ˿��ǿ��Ц�ݣ�����
�������ã���ﲻ���ң���\n",this_object(),me);
        }
        return 1;
}     
