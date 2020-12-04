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
	      set_name("[33mÔË¶¯Ñü°ü[2;37;0m", ({ "chungou waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[31m´¿¹³½«Ë§Ö®±ø£¬³ÖÖ®ÄÜ»Ó¾ü°ÙÍò£¬¿ËµĞÖÆÊ¤£¡
[2;37;0mÕâÊÇÒ»ÌõÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ï¾ÅÁ½¶şÇ®µÄ[31m´¿¹³Ö®Ñü´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;31mÎŞË«[2;37;0m [40mµØ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;33m½ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [31m»ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[1;31mÎŞË«[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[1;34m¾ÙÊÀ[2;37;0m 
ÌåÁé:[1;34m¾ÙÊÀ[2;37;0m °×Ê¯:[35m±ê×¼[2;37;0m ÉÁµç:[31m¾«ÖÂ[2;37;0m 
ÖÜÌì:[33mºÜ¸ß[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞ¡Ê¯Í·[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mµ¶·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "stone");
		set("ownername", "Ğ¡Ê¯Í·");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 247);
    set("armor_prop/defense", 88);
    
    set("armor_prop/neili", 42);
    set("armor_prop/qi", 37);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 72);

    set("wtypeA",13);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",10);
    set("wtypeE",0);
    set("wtypeF",12);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",12);
    set("wtypeJ",8);
    set("wtypeK",9);
    set("wtypeL",14);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 23);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";