// keshang.c

inherit NPC;


                          
string *first_name = ({
    "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
                    });

string *last_name = ({
    "��", "��", "��" ,"��", "��", "��", "��", "��", "��", "ʮ",
                    });                                              
void create()
{
    string name;
    name = first_name[random(sizeof(first_name))];
    name += last_name[random(sizeof(last_name))];
        set_name( name , ({ "ke shang", "trader", "shang" }));
    set("title", "��·����" );
    set("gender", "����" );
        set("age", 15+random(50));
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
        set("no_leave_chuzhou", 1);
        set("long",
                "����һ�������ڸ������֮��Ŀ��̣���ߴ��˲��ٻ��\n");
        set("chat_chance", 10);
        set("chat_msg", ({
(: random_move :),
"����˵������˵ǰ����ǿ���������Ͼ��������ҹ�˰ɡ�����\n",
"����������Χ�����Ҽұ��˵Ŀ�ջ��\n",
 }));
        set("combat_exp", 100000+random(400000));
    set("social_exp", 100000+random(400000));

        set("attitude", "friendly");
        set("no_leave_sizhou", 1);
        setup();
        carry_object( "/clone/misc/cloth" )->wear();

        //carry_object( goods[random(sizeof(goods))]);

        set("possitive_score",100-random(400));
}

int refuse_killing( object who )
{
        object *inv;
        int i;
        message_vision("���̴�е���������������ѽ�� ��������������\n", who);
        inv = all_inventory( environment(this_object()) );
        for ( i = 0; i < sizeof(inv); i++ )
        {
                if( inv[i]->query("id") == "ke shang" && inv[i] != this_object() )
                inv[i]->kill_ob(who);
        }
        return 0;
} 

