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
	set_name("[1;31m����֮��[2;37;0m", ({ "chungou sword", "sword" }));
	set_weight(16591);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m������˧֮������֮�ܻӾ����򣬿˵���ʤ��
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m�Ƴɣ�����ʮ����һ����Ǯ��[31m����֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;36mն����ħ[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;35m����[2;37;0m [1;31mħ[2;37;0m:[1;31m��Ԫ[2;37;0m [1;33m��[2;37;0m:[1;34m����[2;37;0m [32mˮ[2;37;0m:[1;33m��ʥ[2;37;0m [33m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;34m��[2;37;0m:[1;31m��˫[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ��Ԩ:[32m�ֲ�[2;37;0m ����:[1;34m����[2;37;0m 
����:[1;34m����[2;37;0m ��ʯ:[35m��׼[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ����:[1;36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�ɶ�[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "�ɶ�");
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",39);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 58);
    set("weapon_prop/parry", 36);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 89);
    set("weapon_prop/defense", 82);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 77);
    set("weapon_prop/jingli", 77);
    set("weapon_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",13);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 26);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(711);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";