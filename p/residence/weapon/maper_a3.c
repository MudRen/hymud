#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;33m����ս����[2;37;0m", ({ "taibai cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;37m
		�Կ��Ϻ�ӧ  �⹳˪ѩ��		�����հ���  ��������
		ʮ��ɱһ��  ǧ�ﲻ����		���˷���ȥ  ���������
		�й�������  �ѽ�ϥǰ��		���ˡ��캥  ����Ȱ����
		������Ȼŵ  ������Ϊ��		�ۻ�������  ����������
		���Իӽ��  ��������		ǧ���׳ʿ  ���մ�����
		����������  ��������Ӣ		˭�������  ����̫����
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ���ʮ����������Ǯ��[1;37m̫��֮��װ[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[31m�����ױ�[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[1;31m��Ԫ[2;37;0m [36mľ[2;37;0m:[1;31m����[2;37;0m [31m��[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[1;36m����[2;37;0m 
[1;37m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m ��Դ:[34mϸ��[2;37;0m 
����:[35m��׼[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "��ͼһ��");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",56);
		set("armor_prop/percao",64);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 56);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 1888);
    set("armor_prop/defense", 64);
    
    set("armor_prop/neili", 64);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 64);
    set("armor_prop/damage", 1253);

    set("wtypeA",6);
    set("wtypeB",14);
    set("wtypeC",6);
    set("wtypeD",8);
    set("wtypeE",7);
    set("wtypeF",7);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",13);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";