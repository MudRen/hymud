#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "chilian she", "she" }) );
        set("long",
         "�������޿ײ�������ߣ�����������ֻ��һ��·����--����������\n");
        set("nickname", RED "�޿ײ���"NOR);
        
        set("combat_exp", 1300000);
        set("no_arrest",1);
        set_temp("apply/damage",80);
        
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
        carry_object("/clone/weapon/gangdao")->wield();
} 
void init()
{
                ::init();
                add_action("do_get","get");
} 
int do_get(string arg)
{
        string what,where;
        if(!arg) return notify_fail("������ʲô��\n");
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        if((where == "fentou" || where == "��ͷ" ))
        {
                command("say ���ý�ҩ���ȹ�������һ����˵��");
                return 1;
        }
}
