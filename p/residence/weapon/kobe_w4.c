// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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

void create()
{
	set_name("[1;37m̫��֮��[2;37;0m", ({ "taibai sword", "sword" }));
	set_weight(10675);
	if (clonep())
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
[2;37;0m����һ�����ޱȼ�Ӳ��[31m��������[2;37;0m�Ƴɣ��ض�ʮһ��������Ǯ��[1;37m̫��֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;31m������˫[2;37;0m��������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[1;34m����[2;37;0m [1;33m��[2;37;0m:[1;31m����[2;37;0m [31m��[2;37;0m:[1;34m����[2;37;0m [33m��[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[1;31m��˫[2;37;0m 

���滹����һЩ���֣�
����:[1;31m����[2;37;0m ����:[34mϸ��[2;37;0m ��ʯ:[34mϸ��[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�Ʊ�[2;37;0m ������һЩ�� [1;32m�ȷ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "�Ʊ�");
		set("value", 25000);
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",32);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",29);
    set("weapon_prop/dodge", 40);
    set("weapon_prop/parry", 28);
    set("weapon_prop/attack", 48);
    set("weapon_prop/armor", 40);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 51);
    set("weapon_prop/qi", 30);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 48);
    set("weapon_prop/damage", 0);

    set("wtypeA",14);
    set("wtypeB",5);
    set("wtypeC",6);
    set("wtypeD",8);
    set("wtypeE",8);
    set("wtypeF",12);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",5);
    set("wtypeJ",5);
    set("wtypeK",4);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1352);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";