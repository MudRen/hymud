// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[1;32mÑªÕ¶Ö®Ø°Ê×[2;37;0m", ({ "general dagger", "dagger" }));
	set_weight(6694);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
ÑªÕ¶Ö®Ø°Ê×[2;37;0mÕâÊÇÒ»°ÑÓÉ¼«Æä¼áÓ²µÄ[33mÉúÌú[2;37;0mÖÆ³É£¬ÖØÊ®Èı½ïÈıÁ½°ËÇ®µÄ[1;32mÑªÕ¶Ö®Ø°Ê×[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´¼«Æä·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[33mºÜ¸ß[2;37;0m [33mÍÁ[2;37;0m:[32m´Ö²Ú[2;37;0m [1;37mÀ×[2;37;0m:[33mºÜ¸ß[2;37;0m [37mÌì[2;37;0m:[1;36mÍêÃÀ[2;37;0m [40mµØ[2;37;0m:[32m´Ö²Ú[2;37;0m [1;36mÈË[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[33mºÜ¸ß[2;37;0m ÇÉÖÆ:[32m¼«²î[2;37;0m 
°×Ê¯:[36m²»´í[2;37;0m ÍşÁ¦:[36m²»´í[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 13);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 4);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 16);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",3);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",3);
    set("wtypeK",8);
    set("wtypeL",6);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 4);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_dagger(317);
	setup();
}



#include "/obj/ritem/weaponzy.h";