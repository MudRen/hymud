#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
//      set("title","��������");
//      set("nickname","Ц��ص�");
        set("long", "һ����������Ц��Ȼ��������Ů��û����֪��������ʵ��ݣ�����
˵�����������ĵ��ӣ�Ҳ����˵���������������ݡ�\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp",3200000);
                        
        set("max_atman",800);
        set("atman",800);
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1500);
        set("neili",1500);
        
        set("inquiry", ([
                "С��" : "С�̺���ͼ������������ֱ���",
                 "ŷ��������" : "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang ding" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang dang" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "������¥": "������¥��Ȼ�ǹ���������ඣ���˵���������ⲻ�ã�����Ϊԭ�Ϸ����ء�",
                "������ջ": "������ջ���ҿ��ġ�",
                "���˹�": "�����Ƕ��ܹ��ˣ�����˹���������û�����ˡ�",
                "������": "�����������˭�˲��������ﻹ�����������ء�",
                "����": "����ҽ����������֮�ܡ�",
                "���ϵ�": "���ϵ�ר��������˵Ҫ�����İ���������ѧ������������С�",
                "��ԯ����": "�����ֻʣ���Ǽ䵱���ˡ�",
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��С��Ц�������͹�����¥ЪϢ����\n",
        }) );

        set_name("��С��",({"tu xiaojiao","xiaojiao"}));
        set("age",20);
        set("gender","Ů��");
        set("force_factor",60);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        message_vision("$N�����˹������ﲨ��$nһ��򸣵��������ã���\n", this_object(),ob);
        return;
}    
