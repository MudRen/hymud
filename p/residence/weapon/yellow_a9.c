#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;37mÃüÔËÅû·ç[2;37;0m", ({ "bagua armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;37m°ËØÔÓĞ¡°Ğİ¡±¡°Éú¡±¡°ÉË¡±¡°¶Å¡±¡°ËÀ¡±¡°¾°¡±¡°¾ª¡±¡°¿ª¡±Ö®±ğ£¬´´×ÔÖî¸ğÎäºò£¬¼¯ÌìÏÂÍò±äÓÚÒ»Éí£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[32mÓñ²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ïÁãÁ½ÁùÇ®µÄ[1;37m°ËØÔÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[31m¾«ÖÂ[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÇÉÖÆ:[1;36mÍêÃÀ[2;37;0m 
ÌåÁé:[31m¾«ÖÂ[2;37;0m °×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[1;36mÍêÃÀ[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶ÎÒ©Ê¦[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m°µÆ÷[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "¶ÎÒ©Ê¦");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",40);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 72);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 419);
    set("armor_prop/defense", 64);
    
    set("armor_prop/neili", 50);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 219);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",9);
    set("wtypeD",5);
    set("wtypeE",8);
    set("wtypeF",8);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";