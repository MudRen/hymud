#include <ansi.h>
inherit NPC;
void create()
{
        set_name("催命符", ({ "cuiming fu", "fu" }) );
        set("long",
         "他的脸色是死灰色的，似已和这凄迷的冷雾融为一体。鼻子已融入雾里，\n嘴也融人雾里，只剩下那双鬼火般的眼睛。眼睛里没有光，也分不出黑白，\n但却充满了恶毒之意。\n");
        set("nickname", WHT "一见送终"NOR);
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
        if(!arg) return notify_fail("你想拿什么？\n");
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        if((where == "fentou" || where == "坟头" ))
        {
                message_vision("催命符伸手拦住$N.\n",me);
                command("say 想拿解药，先过了我这一关再说。");
                return 1;
        }
}   
