#include <ansi.h>
inherit NPC;
int tell_test();
void create()
{
        set_name("���", ({ "biao ge" }) );
        set("gender", "����");
        set("class", "ghost");
        create_family("����ɽׯ", 3, "����");
        set("combat_exp", 300000);
        set("long",
                "�������⻬���׾��������Ǹ��հ��˿ǵļ�����\n"
        );
        set("inquiry", ([
                "��" : (: tell_test :),
                "mission" :(: tell_test :)
        ]) );
        set("no_arrest",1);
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("sword", 100);
        set_skill("three-sword", 50);

        map_skill("sword", "three-sword");
        setup();
        carry_object(__DIR__"obj/letter");
        carry_object(__DIR__"obj/letter");
        carry_object(__DIR__"obj/cloth2")->wear();
        carry_object(__DIR__"obj/sword3")->wield();
} 
void init()
{
        ::init();
        if(interactive(this_player()) && !is_fighting()) {
                call_out("greeting", 1, this_player());
        }
} 
int tell_test()
{
        object          me; 
        me = this_player();     
        if(me->query_temp("marks/test")) {
                me->set_temp("marks/test", 0);
                tell_object(me, YEL "\n���˰�ɽ���͵ĵ��ӣ����Ʒɣ�����ʦ����������ɽׯ�Եס�"NOR);
                tell_object(me, YEL "\n����������һ���ж࣬������֪�ϵ����ӵ�����Ŀ��"NOR);
                tell_object(me, YEL "\n���Ѱ���һ�����������Ŷ�������������һֱû�л����ͳ�ȥ��"NOR);
                tell_object(me, YEL "\n��ϣ�����ܰ�����غ��͵��䵱����ʯ������С�(accept yes/no?)\n"NOR);
                me->set_temp("marks/�غ�", 1);
                add_action("do_accept", "accept");
                return 1;
        }
        return 0;
} 
int greeting(object me)
{
        object          groom; 
        if( (string)me->query("family/family_name")=="����ɽׯ" ) {
                message_vision(HIY "\n$N��$n�ȵ�����ĵ��Ӳ�С���������ϵ����ӵ�Ů�ˣ�\n"NOR, this_object(), me);
                message_vision(HIR "\n�������������ɣ�\n"NOR, this_object(), me);
        }
        else {
                message_vision(HIY "\n$N��$n�ȵ�����ĵ��Ӳ�С���������ϵ����ӵ�Ů�ˣ�\n"NOR, this_object(), me);
                message_vision(HIR "\n�����������һ���£����������������ɣ�\n"NOR, this_object(), me);
                me->set_temp("marks/test", 1);
        }
        return 1;
} 
int do_accept(string arg)
{ 
        object          me, nroom, letter; 
        if(!arg || (arg != "yes" && arg != "no"))
                return notify_fail("ʲô��\n");
        me = this_player();
        if(!me->query_temp("marks/�غ�")) 
                return notify_fail("ʲô��\n");
        me->set_temp("marks/�غ�", 0);
        if(arg == "yes") {
                letter = present("letter", this_object());
           if(!objectp(letter)) letter=new(__DIR__"obj/letter");
                tell_object(me, CYN"\n���Ʒ�Ц����̫���ˣ������غ������պá�\n"NOR);
                letter->move(me);
//                      tell_object(me, HIY "\n���Ʒ�Ц����̫���ˣ��غ�������һ�����صĵط����´μ������ٸ��㡣\n"NOR);
                tell_object(me, CYN "\n�����������ȥ����\n"NOR);
                message_vision(HIY "\n����������ϰ���һ�£�$n�Ľ����ѿ���һ���󶴣�\n$n�����һ����������ȥ��\n"NOR, this_object(), me);
                me->set_temp("marks/���Ʒ�", 1);
                ///nroom = find_object(AREA_WUDANG"road1");
                ///if(!objectp(nroom)) nroom=load_object(AREA_WUDANG"road1");
                ///me->move(nroom);
                message_vision(HIY "\n$N��ɽ���ϵ�һ��С������������\n"NOR, me);
        }
        else {
                tell_object(me, CYN "\n���Ʒ�Ц�������������㣬�����㲻�Ǽ�ϸ��\n"NOR);
                tell_object(me, CYN "\n����������ȥ���ϵ����ӡ�\n"NOR);
                me->set_temp("marks/����ɽׯ", 1);
                message_vision(HIY "\n����������ϰ���һ�£�$n�Ľ����ѿ���һ���󶴣�\n$n�����һ����������ȥ��\n"NOR, this_object(), me);
                ///nroom = find_object(AREA_WUDANG"house3");
                if(!objectp(nroom)) nroom=load_object("/d/ghost/house3");
                me->move(nroom);
                message_vision(HIY "\n$N����������˳�����\n"NOR, me);
        }
        return 1;
}    
