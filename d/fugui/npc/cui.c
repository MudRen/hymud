#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "cuiming fu", "fu" }) );
        set("long",
         "������ɫ������ɫ�ģ����Ѻ������Ե�������Ϊһ�塣�������������\n��Ҳ�������ֻʣ����˫������۾����۾���û�й⣬Ҳ�ֲ����ڰף�\n��ȴ�����˶�֮�⡣\n");
        set("nickname", WHT "һ������"NOR);
        set("combat_exp", 1200000);
        set("force",500);
        set("max_neili",500);
        set_temp("apply/damage",60);
        set("no_arrest",1);
        set_skill("unarmed", 200);
        set_skill("force",100);
        set_skill("parry",150);
        set_skill("dodge", 150);
        set_skill("move",100);
        set_skill("blade",100);
        set_skill("qiusheng-blade",150);
        set_skill("cloudforce",100);
        set_skill("literate",100);
        set_skill("meng-steps",100);
        set_skill("yunwu-strike",150);
        
        map_skill("unarmed","yunwu-strike");
        map_skill("blade","qiusheng-blade");
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
        map_skill("force","cloudforce");
        map_skill("parry","qiusheng-blade");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/ywhip")->wield();
} 
void init()
{
        ::init();
        add_action("do_get","get");
} 
int do_get(string arg)
{
        string what,where;
        object me;
        me=this_player();
        if(!arg) return notify_fail("������ʲô��\n");
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        if((where == "fentou" || where == "��ͷ" ))
        {
                message_vision("������������ס$N.\n",me);
                command("say ���ý�ҩ���ȹ�������һ����˵��");
                return 1;
        }
}   
