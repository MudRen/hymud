// ��Ա��� /d/city/chuzhou/npc/zhou_yuanwai.c
// by lala, 1997-12-14

inherit NPC;

void create()
{
    set_name( "��Ա��", ({ "zhou yuanwai", "zhou", "yuanwai" }) );
    set( "gender", "����" );
    set( "age", 58 );
    set( "title", "��������" );
    set( "long", @LONG
��Ա���Ǳ����������������������ƺ�������С�Ĺ٣�������Ա�Ȿ�˲�û��
��̫�õĹ٣�Ҳû��������ߵĹ٣�ֻ����һ����֪�ݡ�ͨ��һ��Ĺ�ְ������
������һ��ȽϷ����������ڱ������к�����
LONG
    );

    set("combat_exp", 10000);
    set("social_exp", 20000);
    set("positive_score", 5000);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    setup();
          
    carry_object( "/clone/misc/cloth")->wear();
    carry_object( __DIR__"obj/riben_zheshan")->wield();
}          

