 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("Ҷ����", ({ "ye shuzhen", "ye"}) );
        set("nickname", HIR "ǰ�ΰ�������"NOR);
        set("gender", "Ů��" );
        set("age", 44);
        set("per", 55);
        set("int",30);
        set("attitude","friendly");
        set("max_neili", 1500);
        set("neili", 1500);
        set("force_factor", 10);
        set("long",
"
Ҷ������ؤ���ǰ�ΰ����δȵķ��ˣ�ֻ���δȲ��ź�������ڴˡ�
\n"
        );
        set("combat_exp", 4);
        set("inquiry", ([
                "�Ϲ���" : (: kill_him :),
                "master nangong" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear(); 
} 
int kill_him()
{
        command("say �Ϲ�������ΪТ˳��ÿ������һ�룬��δ��ϣ�\n");
        return 1;
} 
int accept_object(object who, object ob)
{
        if(ob->name() == "�����ܺ�"){
        command("say ��д����Ҳ���򲻵��ԣ��Ϲ�Ұ�Ĳ�����������һ��ˮ
�����������ֺ��ܣ�������һ�����׵ĸ�磬�����ĺ�������
���˲��������������������գ���ʵ�Ϲ���������ʮ���ɵĶ����ӣ�
���䳤������������ŵ����¡�\n");
        who->set_temp("��һ��ˮ",1);    
        if(!who->query("m_success/ؤ��ǰ��"))
        {
                who->set("m_success/ؤ��ǰ��",1);
                who->add("score",100); 
        }
                return 1;
        }
    return 0;
} 
