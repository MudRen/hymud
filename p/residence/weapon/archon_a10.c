#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[37m�׵�֮����[2;37;0m", ({ "leidian waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[37m�׵�֮����[2;37;0m����һ�����ޱȼ�Ӳ��[31m��������[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ��ض������һǮ��[37m�׵�֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[32mˮ[2;37;0m:[1;31m��˫[2;37;0m [33m��[2;37;0m:[31m����[2;37;0m [1;35m��[2;37;0m:[1;33m��ʥ[2;37;0m 
[1;37m��[2;37;0m:[33m�ܸ�[2;37;0m [1;34m��[2;37;0m:[1;35m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��Ԫ[2;37;0m ����:[36m����[2;37;0m ����:[36m����[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m 
����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "����");
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 630);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 44);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 93);

    set("wtypeA",5);
    set("wtypeB",4);
    set("wtypeC",12);
    set("wtypeD",6);
    set("wtypeE",6);
    set("wtypeF",10);
    set("wtypeG",6);
    set("wtypeH",11);
    set("wtypeI",6);
    set("wtypeJ",3);
    set("wtypeK",3);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";