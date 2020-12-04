#include <ansi.h>
#define MAX_EXP         70000

inherit NPC;

int ask_food(object me);
int ask_job(object me);
void give_prise(object me);

void create()
{
        set_name("�﷿ֵ��", ({ "kan shou", "kan" }) );

        set("class","jinghai");
        create_family("����", 4, "����");

        set("gender", "����" );
        set("age", 35);
        set("long", "����һλ׳�꺺�ӣ�ר��
�տ�����Ļ﷿����Ҫ�Ƕ�
�˿�������Ҫ��Ե�(food)��\n");
        set("attitude", "peaceful");
        set("inquiry",([
        "�Ե�" : (: ask_food :),
        "food" : (: ask_food :),
        "job"  : (: ask_job :),
]));

        set("combat_exp", 2050);
        set("str", 67);

        setup();

        carry_object(__DIR__"obj/pijia")->wear();
}

int ask_food(object me)
{
        object *inv,food;
        int n,i;

        if(!me || me->query("class") != "jinghai")
                return 0;
        if(base_name(environment()) != query("startroom"))
                return 0;

        if((int)me->query("food") >= (int)me->max_food_capacity() )
        {
                message_vision(CYN"$N���˿�$n˵��������ȥ�úò�����\
����ô������ǳԣ���������������ҡ���\n"NOR,this_object(),me);
                return 1;
        }

        if(me->query_temp("jinghai_ask_food"))
        {
                message_vision(CYN"$N���˿�$n˵���������Ǹո������ô��Ҫ��\
����û�У�����\n"NOR,this_object(),me);
                return 1;
        }

        inv = all_inventory(me);

        n = sizeof(inv);
        

for(i=0;i<n;i++)
        {
                if(inv[i]->is_food() && inv[i]->query("food_remaining"))
                        break;
        }

        if(i<n)
        {
                message_vision(CYN"$N���˿�$n˵���������ǲ��ǻ��гԣ�\
�������������ҡ����˷ѡ���\n"NOR,this_object(),me);
                return 1;
        }

        message_vision("$N���ͷ��������Ŵ�׷��ݸ���$n����\n",this_object(),me);
        food = new(__DIR__"obj/mifan");
        food->move(me);
        food = new(__DIR__"obj/mifan");
        food->move(me);
        me->set_temp("shaolin_ask_food",1);
        call_out("finish",120,me);
        return 1;
}

void finish(object me)
{
        if(!me)
        me->delete_temp("jinghai_ask_food");            
}


