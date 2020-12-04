// ��ũ��ģΣУñ�׼�ļ�  /d/menpai/shennong/npc/ShennongNpc.c
// by lala, 1998-01-21

#include <ansi.h>
inherit NPC;

void Greeting( object ppl );

void setup()
{
    mapping my = this_object()->query_entire_dbase();
                                                                                                     
    if( !my["title"]          ) set("title", BLU"��ũ�����"NOR);
    if( !my["gender"]         ) set("gender",            "����");
    if( !my["age"]            ) set("age",     18 + random(50) );
    if( !my["attitude"]       ) set("attitude",     "peaceful" );
                                
    if( !my["max_force"]      ) set("max_force",            100);
    if( !my["force"]          ) set("force",                100);
    if( !my["force_factor"]   ) set("force_factor",           5);
    if( !my["max_kee"]        ) set("max_kee",              225);
    if( !my["max_sen"]        ) set("max_sen",              225);
    if( !my["kee"]            ) set("kee",                  225);
    if( !my["sen"]            ) set("sen",                  225);
                                    
    if( !my["combat_exp"]     ) set("combat_exp",         10000);
    if( !my["social_exp"]     ) set("social_exp",         15000);
    if( !my["negative_score"] ) set("negative_score",       800);

    if( !my["inquiry"]        )
        set("inquiry",  ([
            "here"      :   "�ⲻ��������ɽ��ǰ��������ļһ��ס�������",
            "rumors"    :   "�ϴα��ﵽ����ɽ��ҩ���������ɵļһﶯ���֡�",    
            "��ũ��"    :   "���������ũ��ڴ���պ�������",
            "������"    :   "����ס������ǰ�һ�ϴ��Ǹ�ʲô���Ӿ�ɱ�����Ǻü������֣�",
            "����ɽ"    :   "�ⲻ��������ɽ��ǰ��������ļһ��ס�������",
            "������"    :   "�������ɵļһ�ס�ĵط����������Ҫƽ�����ǣ�ռ���⽣������",
            "˾����"    :   "���Ǳ���İ���������ô������������˼ҵ����֣�",
            "���չ�"    :   "��������ô֪���ģ������첻Ҫ����",
            "ͨ���"    :   "��˵�ⳤ������ɽ��Ĳݰ������Ի����������ķ�����",
            "���Ӿ�"    :   "�����ɵļһ�������ݣ��ϴ�ɱ�����Ǻü��������أ�",
            "������"    :   "�����⣬�������չ���һ�ְ������������Ͼ����˼��š�",
        ]) );

    if( !my["talk_msg"]       )
        set("talk_msg", ({
            "��������ũ���Բ�ҩ����ҩΪ����������ҩ����һ��Ҫ�¹��򡣡�",
            "�������أ����Ǻ�������������Ȼû��ʲô���飬����ԭҲû�����ӡ���",
            "�������ɵļһ����ǿɶ�����Ҫ�����Ǻ�ɽ��ҩ�����Ǿ�Ȼ�Ҳ��ã���",
            "���ߣ��������ɽ�ֲ��ǽ��ǵ����԰������ƾʲô�����ã���",
            "��������ũ��������ɶ��������֣����˲�С�Ŀ��������˺ü������֣���",
            "���Ǹ��������Ӿص�С�����ǿɶ�ɱ�����������õ��֣�������",
            "����һ���������������ɱ����Ȯ���������Ǳ�����Ĩ���Ӱɡ���",
            "����翷����չ���������ķ�ʥʹ������ɽͯ�ѵ����˵Ҫƽ�������ɡ���",
            "����ʵ���չ���ҪŪ�����������赡������ܣ���ҪŪ�������ܾͱ���ռ�˽���������",
        }) );  
    if( !my["family"]         )
        set("family",   ([
            "family_name"   :   "��ũ��",
            "master_name"   :   "˾����",
            "master_id"     :   "sikong xuan",
            "generation"    :   2,
            "title"         :   "����",
        ]) );
    ::setup();
}




void init()
{
	object me=this_player();
      remove_call_out( "greeting" );
       call_out( "greeting", 1, me );
}

void greeting( object me )
{

    if ( !me 
        || environment( me ) != environment() )
        return;

            if( me->query("family/family_name") == "�������ɶ���" 
    ||  me->query("family/family_name") == "������������" )    
    {
    message_vision( "$N����$n�����Ц����������Щ�����ɵĹ��������������� ��\n",
        this_object(), me );
    this_object()->kill_ob(me);
    me->fight_ob(this_object());
   }
}


void attempt_apprentice( object ppl )
{
    command( "say ���Ǻǣ�����ֻ�а������˿�����ͽ���㻹��ȥ�ݰ��������˼Ұɣ���" );
    return;
}

            