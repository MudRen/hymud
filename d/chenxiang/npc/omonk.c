 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�Ϻ���", ({ "old monk","monk" }) );
        set("gender", "����" );
        set("age", 57);
        set("long", "�Ϻ�����ɫ����Ŀ¶���⣬��ϧ�������°��ϳ��˸������ӡ�\n");
        set("combat_exp", 100000);
        setup();
        carry_object(__DIR__"obj/mcloth")->wear();
} 
int cure_arong(object me)
{
         if (query("cured")){
                command("say ��û�������㲻�÷����ˣ�");
                return 1;
        }
        if (me->query_temp("marks/cured_monk")) {
                command("say �Դ����ϴ������ι������Ѿ��ö��ˡ�");
                return 1;
        }
                
        if(!query("cured")) {
                tell_object(me,"�Ϻ����°��ϵĴ�����Խ��ԽС��������ʧ�ˣ�����\n");
                set("long","�Ϻ�����ɫ����Ŀ¶���⣬�������˵����ӣ�\n");
                tell_object(me,"�Ϻ��и��˵��������ͷ����̫���ˣ���֪��ô����Ա�������Ҳ�и������ӣ�
                ��������԰����Ļ�����һ�������ܶ�ô���\n");
                me->set_temp("marks/cured_monk",1);
                set("cured",1);
        } 
        return 1;
}
